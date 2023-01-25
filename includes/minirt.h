/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:23:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 23:54:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include "mlx.h"
# include "algebra.h"
# include "structs.h"
# include "my_mlx.h"
# include <fcntl.h>

# define EPSILON 1E-4

# define ERRARG 1
# define ERRFMT 2
# define ERRFILE 3
# define SPACES " \t"

# define SCREEN_WIDTH 11
# define SCREEN_HEIGHT 11

# define INTER_MAX 

typedef	struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	img;

	t_world		world;
	t_camera	camera;
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

t_data		*data(void);
t_light		*light(void);
t_world		*world(void);
t_list		*objects(void);
t_camera	*camera(void);

/* args.c file */

int			check_args(int argc, char **argv);
void		file_init(t_file *file);

/* utils_temp*/

void		tuple_inspect(t_t3d tuple);

/* RAYS */

t_ray		ray(t_p3d origin, t_v3d vector);

t_p3d		position(double scalar, t_ray _ray);

t_ray		ray_for_pixel(int x, int y);

/* MATERIAL */

t_material	material(void);

/* OBJECTS */

t_object	*sphere(void);
t_v3d		normal_at(t_object obj, t_p3d _point);
t_v3d		reflect(t_v3d in, t_v3d normal);


// intersection

t_intx		*new_intersection(double t, t_object *obj);
void		create_intersection(t_list **list, double t, t_object *obj);
t_intxs		intersect(t_object *obj, t_ray _ray);

t_intx		*hit(t_intxs intersections);
t_ray		transform(t_matrix mx, t_ray _ray);

/* LIGHT */

typedef struct s_lgt
{
	t_c3d		effective_color;;
	t_c3d		diffuse_color;
	t_c3d		specular_color;
	t_c3d		ambient_color;
	t_c3d		result_color;
	t_v3d		lightv;;
	double		light_dot_normal;
	t_lgt_param	params;
}			t_lgt;

void		point_light(t_p3d position, t_c3d color);
t_c3d		lighting(t_material m, t_light light, t_lgt_param params);

/* COLORS */

t_rgb		tcolor_to_rgb(t_c3d color);
t_c3d		rgb_to_tcolor(t_rgb rgb);

/* WORLD */

typedef struct s_sort
{
	int		init;
	t_list	*partition;
}			t_sort;

void		default_world(void);
t_c3d		color_at(t_ray ray);

void		create_object(t_object	*object);

t_intxs		intersect_world(t_ray _ray);
void		sort_intersections(t_list *lst);
t_comp		prepare_computations(t_intx inter, t_ray ray);
t_c3d		shade_hit(t_comp comps);

void		view_transformation(t_view view, t_matrix *result);

void		render(void);

/* CAMERA */

void	set_camera(int hsize, int vsize, double field_of_view);

/* CLEAN*/

void		clean_program(void);

/* DEMOS*/

void		mlx_demo(void);
void		hello_world_img(void);
void		clock_demo(void);

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

void		sphere_demo(void);
void		sphere_3d_demo(void);

#endif