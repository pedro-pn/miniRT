/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:23:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/18 15:25:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "algebra.h"
# include "my_mlx.h"
# include <fcntl.h>

# define EPSILON 1E-4

# define ERRARG 1
# define ERRFMT 2
# define ERRFILE 3
# define SPACES " \t"

# define SCREEN_WIDTH 200
# define SCREEN_HEIGHT 200

# define INTER_MAX 

typedef	struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	img;

	t_list		*objects;

}			t_data;


typedef struct s_file
{
	t_list	*ambient;
	t_list	*camera;
	t_list	*light;
	t_list	*sphere;
	t_list	*plane;
	t_list	*cylinder;
	
}			t_file;

typedef struct s_scene_val
{
	int	camera;
	int	ambient;
	int	light;
}			t_scene_val;

/* control */

t_data	*data(void);

/* args.c file */

int		check_args(int argc, char **argv);
void	file_init(t_file *file);

/* utils_temp*/

void	tuple_inspect(t_t3d tuple);

/* RAYS */

typedef struct s_ray
{
	t_p3d	origin;
	t_v3d	direction;
}			t_ray;

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

	t_p3d	origin;

	double		radius;
	t_rgb		color;

	t_matrix	transform;
}			t_object;

t_object	*sphere(void);
t_v3d		normal_at(t_object obj, t_p3d _point);

// intersection

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

t_intx	*new_intersection(double t, t_object *obj);
void	create_intersection(t_list **list, double t, t_object *obj);
t_intxs	intersect(t_object *obj, t_ray _ray);

t_ray	ray(t_p3d origin, t_v3d vector);
t_p3d	position(double scalar, t_ray _ray);

t_intx	*hit(t_intxs intersections);
t_ray	transform(t_matrix mx, t_ray _ray);

/* CLEAN*/

void	clean_program(void);

/* DEMOS*/

void	mlx_demo(void);
void	hello_world_img(void);
void	clock_demo(void);

typedef struct s_projectile
{
	t_p3d	position;
	t_v3d	velocity;
}			t_projectile;

typedef struct s_environment
{
	t_v3d	gravity;
	t_v3d	wind;
}			t_environment;

t_projectile	tick(t_environment env, t_projectile proj);
void			projectile_demo(void);

typedef struct s_sdemo
{
	t_object	*_sphere;
	double		wall_size;
	double		wall_z;
	double		pixel_size;
	double		half_wall;
	double		world_x;
	double		world_y;
	t_p3d		ray_origin;
}			t_sdemo;

void	sphere_demo(void);

#endif