/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:00:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/11 21:12:11 by pedro            ###   ########.fr       */
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

/* PATTERN */

typedef struct s_patt	t_patt;
typedef t_c3d	(*t_patt_at)(t_patt, t_p3d);

struct s_patt
{
	t_c3d		a;
	t_c3d		b;

	double		width;
	double		height;

	t_matrix	transform;
	t_patt_at	patt_at;

	t_bool		has_pattern;
};

typedef struct s_lgt_param
{
	t_p3d	position;
	t_v3d	eyev;
	t_v3d	normalv;
	t_bool	in_shadow;
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
	double	reflective;
	double	transparency;
	double	refractive_index;
}			t_material;

/* OBJECTS */

typedef enum e_objs
{
	COLOR,
	SPHERE,
	PLANE,
	CUBE,
	CYLINDER,
	CONE,
	GROUP,
	OBJECT,
}		t_objs;

typedef struct s_object	t_object;
typedef struct s_intxs	t_intxs;
typedef struct s_object	t_group;

typedef t_intxs	(*t_intersect)(t_object *, t_ray);
typedef t_v3d	(*t_normal_at)(t_object, t_p3d);
typedef void	(*t_clean)(void *);

struct s_object
{
	int			id;
	int			type;

	t_p3d		origin;

	double		radius;
	t_rgb		color;

	double		maximum;
	double		minimum;
	t_bool		closed;

	t_matrix	transform;

	t_material	material;
	t_patt		pattern;

	t_intersect	intersect;
	t_normal_at	normal;
	
	t_list		*group;
	t_object	*parent;
	
	t_clean		clean;
};



/* INTERSECTIONS */

typedef struct s_intx
{
	double		t;
	t_object	*object;
}			t_intx;

struct s_intxs
{
	int		count;
	t_list	*intersections;
};

/* WORLD */

typedef struct s_world
{
	t_list	*objects;
	t_light	light;
}			t_world;

typedef struct s_comp
{
	t_p3d		point;
	t_p3d		over_point;
	t_p3d		under_point;
	t_v3d		eyev;
	t_v3d		normalv;
	t_v3d		reflectv;

	t_object	*object;
	double		t;
	t_bool		inside;

	double		n1;
	double		n2;
	double		n_ratio;
	double		cos_i;
	double		cos_t;
	double		sin2_t;
}			t_comp;

typedef struct s_view
{
	t_p3d	from;
	t_p3d	to;
	t_v3d	up;
}			t_view;

/* CAMERA */

typedef struct s_camera
{
	int			hsize;
	int			vsize;

	double		half_width;
	double		half_height;

	double		field_of_view;
	double		pixel_size;

	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;

	t_matrix	transform;
	t_mlx_img	img;
}			t_camera;

#endif