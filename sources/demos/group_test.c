/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:28:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/08 15:10:56 by ppaulo-d         ###   ########.fr       */
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

t_object	*middle_sphere(void)
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
	return (middle);
}

t_object	*right_cylinder(void)
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
	translation(vector(1.0, 0.5, -0.5), &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, rot_x, &mx_1);
	mx_product(mx_1, scal, &right->transform);
	right->material.color = tcolor(0.5, 0.5, 0.5);
	right->material.diffuse = 0.7;
	right->material.specular = 0.3;
	return (right);
}

t_object	*left_cone(void)
{
	t_object	*left;
	t_matrix	trans;
	t_matrix	scal;

	left = cone();
	left->material.transparency = 0.8;
	left->material.shininess = 200.0;
	left->material.refractive_index = 1.52;
	left->material.reflective = 0.5;
	left->closed = true;
	left->maximum = 0;
	left->minimum = -1;
	translation(vector(-1.25, 1, -1.75), &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, scal, &left->transform);
	left->material.color = tcolor(1, 1, 1);
	left->material.diffuse = 0.7;
	left->material.specular = 0.3;
	return (left);
}

static void	create_group(t_v3d position)
{
	t_group		*g;
	t_matrix	trans;
	t_matrix	scal;

	g = group();
	translation(position, &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, scal, &g->transform);
	add_child(g, middle_sphere());
	add_child(g, left_cone());
	add_child(g, right_cylinder());
	create_object(g);
}

static void create_world_objects(void)
{
	// set_floor();
	// background();
	create_group(vector(1 ,1 ,1));
	create_group(vector(-1 ,-1 ,1));
	create_group(vector(-1 ,1 ,1));
	create_group(vector(1 ,-1 ,1));
	create_group(vector(-1 ,3 ,1));
	create_group(vector(1 ,3 ,1));
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

void	group_test(void)
{
	create_world_objects();
	create_world_camera();
	render();
	mlx_save_img_to_ppm(image(), "group_test.ppm");
}
