/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:23:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/16 16:46:36 by ppaulo-d         ###   ########.fr       */
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

typedef	struct s_data
{
	void		*mlx;
	void		*mlx_win;
	t_mlx_img	img;

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

t_ray	ray(t_p3d origin, t_v3d vector);
t_p3d	position(double scalar, t_ray _ray);

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

#endif