/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_demo_v3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:28:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 17:21:23 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_floor(void)
{
	t_object	*floor;

	floor = plane();
	floor->material.transparency = 0.9;
	floor->material.reflective = 1;

	floor->material.color = tcolor(1, 0.9, 0.9);
	floor->material.specular = 0;
	create_object(floor);
}

void	background(void)
{
	t_object	*background;
	t_matrix	rot_x;
	t_matrix	trans;

	background = plane();
	rotation_x(MY_PI / 2, &rot_x);
	translation(vector(0, 0, 6), &trans);
	mx_product(trans, rot_x, &background->transform);
	background->pattern = checkers_pattern(white(), black());
	background->material.reflective = 0.7;
	create_object(background);
}

void	left_wall(void)
{
	t_object	*left_wall;
	t_matrix	rot_y;
	t_matrix	rot_x;
	t_matrix	trans;
	t_matrix	mx1;

	left_wall = plane();
	translation(vector(-5, 0, 0), &trans);
	rotation_x(MY_PI / 2.0, &rot_x);
	rotation_y(-MY_PI / 4.0, &rot_y);
	mx_product(trans, rot_y, &mx1);
	mx_product(mx1, rot_x, &left_wall->transform);
	left_wall->material.color = tcolor(1, 0.9, 0.9);
	left_wall->material.specular = 0;
	create_object(left_wall);
}

void	right_wall(void)
{
	t_object	*right_wall;
	t_matrix	rot_y;
	t_matrix	rot_x;
	t_matrix	trans;
	t_matrix	mx1;

	right_wall = plane();
	translation(vector(5, 0, 0), &trans);
	rotation_x(MY_PI / 2.0, &rot_x);
	rotation_y(MY_PI / 4.0, &rot_y);
	mx_product(trans, rot_y, &mx1);
	mx_product(mx1, rot_x, &right_wall->transform);
	right_wall->material.color = tcolor(1, 0.9, 0.9);
	right_wall->material.specular = 0;
	create_object(right_wall);
}

void	middle_sphere(void)
{
	t_object	*middle;

	middle = sphere();
	translation(vector(-0.5, 1, 0.5), &middle->transform);
	middle->material.color = tcolor(1, 0.6, 0.6);
	middle->material.diffuse = 0.2;
	middle->material.specular = 0.3;
	middle->material.transparency = 0.6;
	middle->material.ambient = 0.4;
	middle->material.refractive_index = 2.0;
	create_object(middle);
}

void	right_sphere(void)
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

void	right_cylinder(void)
{
	t_object	*right;
	t_matrix	trans;
	t_matrix	scal;
	t_matrix	rot_x;
	t_matrix	mx_1;

	right = cylinder();
	right->material.reflective = 1.0;
	right->closed = true;
	right->maximum = 2;
	right->minimum = -2;
	rotation_x(-MY_PI / 4, &rot_x);
	translation(vector(1.5, 0.5, -0.5), &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, rot_x, &mx_1);
	mx_product(mx_1, scal, &right->transform);
	right->material.color = tcolor(0.5, 0.5, 0.5);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	create_object(right);
}

void	left_sphere(void)
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
//	left_wall();
//	right_wall();
	middle_sphere();
	background();
	//left_sphere();
	// right_sphere();
	right_cylinder();
	point_light(point(-10, 10, -10), tcolor(1, 1, 1));
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(500, 500, MY_PI / 3);
	view.from = point(0, 1.5, -5);
	view.to = point(0, 1, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	world_demo_v3(void)
{
	create_world_objects();
	create_world_camera();
	render();
	ft_lstclear(&world()->objects, free);
	mlx_save_img_to_ppm(image(), "world_demo_refs2.ppm");
}
