/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:23:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 19:44:47 by pedro            ###   ########.fr       */
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
# include <pthread.h>

# define EPSILON 1E-4

# define ERRARG 1
# define ERRFMT 2
# define ERRFILE 3
# define SPACES " \t"

# define SCREEN_WIDTH 11
# define SCREEN_HEIGHT 11

# define ITER_MAX 5
# define THREAD_NUM 12

typedef	struct s_data
{
	void		*mlx;
	void		*mlx_win;

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

typedef struct s_task
{
	int	x;
	int	y;
}			t_task;

/* control */

t_data			*data(void);
t_light			*light(void);
t_world			*world(void);
t_list			*objects(void);
t_camera		*camera(void);
pthread_mutex_t	*buffer_mutex(void);
pthread_mutex_t	*task_mutex(void);

/* args.c file */

int				check_args(int argc, char **argv);
void			file_init(t_file *file);

/* UTILS */

void			print_progress(void);

/* utils_temp*/

void			tuple_inspect(t_t3d tuple);

/* RAYS */

t_ray			ray(t_p3d origin, t_v3d vector);

t_p3d			position(double scalar, t_ray _ray);
t_ray			ray_transf_inverse(t_matrix _transform, t_ray _ray);

t_ray			ray_for_pixel(int x, int y);

/* MATERIAL */

t_material		material(void);

/* OBJECTS */

int				object_count(void);
t_v3d			normal_at(t_object obj, t_p3d _point);
t_v3d			reflect(t_v3d in, t_v3d normal);

// spheres
t_object		*sphere(void);
t_object		*glass_sphere(void);

t_intxs			intersect_sphere(t_object *obj, t_ray _ray);
t_v3d			sphere_normal_at(t_object obj, t_p3d point);

// planes

t_object		*plane(void);

t_v3d			plane_normal_at(t_object plane, t_p3d point);
t_intxs			intersect_plane(t_object *plane, t_ray ray);

// cubes

t_object		*cube(void);
t_intxs			intersect_cube(t_object *cube, t_ray ray);
t_v3d			cube_normal_at(t_object cube, t_p3d point);

// cylinders

t_object		*cylinder(void);
t_intxs			intersect_cylinder(t_object *cylinder, t_ray ray);
t_v3d			cylinder_normal_at(t_object object, t_p3d point);
void			intersect_caps(t_object *cylinder, t_ray ray, t_intxs *xs);

// cones

t_object		*cone(void);
t_intxs			intersect_cone(t_object *cone, t_ray ray);

// intersection

t_intx			*new_intersection(double t, t_object *obj);
void			create_intersection(t_intxs *xs, double t, t_object *obj);
t_intxs			empty_intersection(void);
t_bool			check_valid_intersection(t_object cy, t_ray ray, double t);


t_intx			*hit(t_intxs intersections);
t_ray			transform(t_matrix mx, t_ray _ray);

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

void			point_light(t_p3d position, t_c3d color);
t_c3d			lighting(t_object obj, t_light light, t_lgt_param params);

/* COLORS */

t_rgb			tcolor_to_rgb(t_c3d color);
t_c3d			rgb_to_tcolor(t_rgb rgb);
t_c3d			black(void);
t_c3d			white(void);

/* PATTERNS*/

t_patt			pattern(t_c3d color_a, t_c3d color_b);
t_c3d			pattern_at(t_object obj, t_p3d point);

//stripes

t_patt			stripe_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			stripe_at(t_patt patt, t_p3d point);

// gradient

t_patt			gradient_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			gradient_at(t_patt patt, t_p3d point);

// ring

t_patt			ring_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			ring_at(t_patt patt, t_p3d point);

// checkers

t_patt			checkers_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			checkers_at(t_patt patt, t_p3d point);

// uv chckers

t_patt			sphere_checkers(double wdt, double hgt, t_c3d color_a,
					t_c3d color_b);
t_c3d			sphere_checkers_at(t_patt patt, t_p3d point);
t_p3d			spherical_map(t_p3d	point);


// radial

t_patt			radial_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			radial_at(t_patt patt, t_p3d point);

// blended stripes

t_patt			blended_strp_pattern(t_c3d color_a, t_c3d color_b);
t_c3d			blended_strp_at(t_patt patt, t_p3d point);

/* REFLECTION */

t_c3d			reflected_color(t_comp comps, int remaining);

/* REFRACTION*/

t_c3d			refracted_color(t_comp comps, int remaining);
void			snell_law(t_comp *comps);

/* FRESNEL*/

double			schlick(t_comp comps);

/* WORLD */

typedef struct s_sort
{
	int		init;
	t_list	*partition;
}			t_sort;

void			default_world(void);
t_c3d			color_at(t_ray ray, int remaining);

void			create_object(t_object	*object);

t_intxs			intersect_world(t_ray _ray);
void			sort_intersections(t_list *lst);
t_comp			prepare_computations(t_intx *inter, t_ray ray, t_intxs xs);
t_c3d			shade_hit(t_comp comps, int remaining);
t_bool			is_shadowed(t_p3d point);

void			view_transformation(t_view view, t_matrix *result);

void			render(void);
void			render_task(t_task task);

/* THREADS*/

int				*task_count(void);
void			start_threads(t_task *tasks);


/* CAMERA */

void			set_camera(int hsize, int vsize, double field_of_view);

/* CLEAN*/

void			clean_program(void);

/* DEMOS*/

void			mlx_demo(void);
void			hello_world_img(void);
void			clock_demo(void);

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

void			sphere_demo(void);
void			sphere_3d_demo(void);
void			world_demo(void);
void			world_demo_v2(void);
void			world_demo_v3(void);
void			book_cover(void);

#endif
