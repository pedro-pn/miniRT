/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_demo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 12:34:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 14:18:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_floor(void)
{
	t_object	*floor;

	floor = sphere();
	scaling(vector(10, 0.01, 10), &floor->transform);
	floor->material.color = tcolor(1, 0.9, 0.9);
	floor->material.specular = 0;
	create_object(floor);
}

static void	left_wall(void)
{
	t_object	*left_wall;
	t_matrix	rot_y;
	t_matrix	rot_x;
	t_matrix	trans;
	t_matrix	scal;
	t_matrix	mx1;
	t_matrix	mx2;

	left_wall = sphere();
	scaling(vector(10, 0.01, 10), &scal);
	translation(vector(0, 0, 5), &trans);
	rotation_y(-MY_PI / 4.0, &rot_y);
	rotation_x(MY_PI / 2.0, &rot_x);
	mx_product(trans, rot_y, &mx1);
	mx_product(mx1, rot_x, &mx2);
	mx_product(mx2, scal, &left_wall->transform);
	left_wall->material.color = tcolor(1, 0.9, 0.9);
	left_wall->material.specular = 0;
	create_object(left_wall);
}

static void	right_wall(void)
{
	t_object	*right_wall;
	t_matrix	rot_y;
	t_matrix	rot_x;
	t_matrix	trans;
	t_matrix	scal;
	t_matrix	mx1;
	t_matrix	mx2;

	right_wall = sphere();
	scaling(vector(10, 0.01, 10), &scal);
	translation(vector(0, 0, 5), &trans);
	rotation_y(MY_PI / 4.0, &rot_y);
	rotation_x(MY_PI / 2.0, &rot_x);
	mx_product(trans, rot_y, &mx1);
	mx_product(mx1, rot_x, &mx2);
	mx_product(mx2, scal, &right_wall->transform);
	right_wall->material.color = tcolor(1, 0.9, 0.9);
	right_wall->material.specular = 0;
	create_object(right_wall);
}

static void	middle_sphere(void)
{
	t_object	*middle;

	middle = sphere();
	translation(vector(-0.5, 1, 0.5), &middle->transform);
	middle->material.color = tcolor(0.1, 1, 0.5);
	middle->material.diffuse = 0.7;
	middle->material.specular = 0.3;
	create_object(middle);
}

static void	right_sphere(void)
{
	t_object	*right;
	t_matrix	trans;
	t_matrix	scal;

	right = sphere();
	translation(vector(1.5, 0.5, -0.5), &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, scal, &right->transform);
	right->material.color = tcolor(0.5, 1, 0.1);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	create_object(right);
}

static void	left_sphere(void)
{
	t_object	*left;
	t_matrix	trans;
	t_matrix	scal;

	left = sphere();
	translation(vector(-1.5, 0.33, -0.75), &trans);
	scaling(vector(0.33, 0.33, 0.33), &scal);
	mx_product(trans, scal, &left->transform);
	left->material.color = tcolor(1, 0.8, 0.1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	create_object(left);
}

static void create_world_objects(void)
{
	set_floor();
	left_wall();
	right_wall();
	middle_sphere();
	left_sphere();
	right_sphere();
	set_light(point(-10, 10, -10), 1.0);
	set_ambient_light(1.0, white_rgb());
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(100, 100, MY_PI / 3);
	view.from = point(0, 1.5, -5);
	view.to = point(0, 1, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	world_demo(void)
{
	create_world_objects();
	create_world_camera();
	render();
	mlx_save_img_to_ppm(image(), "world_demo.ppm");
}
