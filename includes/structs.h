/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:00:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:35:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "algebra.h"
# include "my_mlx.h"

/* LIGHT */
typedef struct s_light
{
	t_p3d	position;
	t_c3d	color;

}			t_light;

typedef struct s_lgt_param
{
	t_p3d	position;
	t_v3d	eyev;
	t_v3d	normalv;
}			t_lgt_param;

/* RAY */
typedef struct s_ray
{
	t_p3d	origin;
	t_v3d	direction;
}			t_ray;

/* MATERIAL */

typedef struct s_material
{
	t_c3d	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}			t_material;

/* OBJECTS */

typedef enum e_objs
{
	SPHERE,
	PLANE,
	CYLINDER,
}		t_objs;

typedef struct s_object
{
	int			id;
	int			type;

	t_p3d		origin;

	double		radius;
	t_rgb		color;

	t_matrix	transform;

	t_material	material;
}			t_object;

/* INTERSECTIONS */

typedef struct s_intx
{
	double		t;
	t_object	*object;
}			t_intx;

typedef struct t_intxs
{
	int		count;
	t_list	*intersections;
}			t_intxs;

/* WORLD */

typedef struct s_world
{
	t_list	*objects;
	t_light	light;
}			t_world;

typedef struct s_comp
{
	t_p3d		point;
	t_v3d		eyev;
	t_v3d		normalv;
	t_object	*object;
	double		t;
	t_bool		inside;
}			t_comp;

typedef struct s_view
{
	t_p3d	from;
	t_p3d	to;
	t_v3d	up;
}			t_view;

#endif