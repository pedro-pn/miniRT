/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer_cover.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 13:02:25 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 14:18:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_material	white_material(void)
{
	t_material m;

	m.color = white();
	m.diffuse = 0.7;
	m.ambient = 0.1;
	m.specular = 0;
	m.reflective = 0.1;
	return (m);
}

static t_material	blue_material(void)
{
	t_material	m;
	
	m = white_material();
	m.color = tcolor(0.537, 0.831, 0.914);
	return (m);
}

static t_material	red_material(void)
{
	t_material	m;
	
	m = white_material();
	m.color = tcolor(0.941, 0.322, 0.388);
	return (m);
}

static t_material	purple_material(void)
{
	t_material	m;
	
	m = white_material();
	m.color = tcolor(0.373, 0.404, 0.550);
	return (m);
}

static void	standard_transform(t_matrix *result)
{
	t_matrix	trans;
	t_matrix	scal;

	translation(vector(1, -1, 1), &trans);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(trans, scal, result);
}

static void	large_object(t_matrix *result)
{
	t_matrix	standard;
	t_matrix	scal;

	standard_transform(&standard);
	scaling(vector(3.5, 3.5, 3.5), &scal);
	mx_product(standard, scal, result);
}

static void	medium_object(t_matrix *result)
{
	t_matrix	standard;
	t_matrix	scal;

	standard_transform(&standard);
	scaling(vector(3.0, 3.0, 3.0), &scal);
	mx_product(standard, scal, result);
}

static void	small_object(t_matrix *result)
{
	t_matrix	standard;
	t_matrix	scal;

	standard_transform(&standard);
	scaling(vector(2.0, 2.0, 2.0), &scal);
	mx_product(standard, scal, result);
}

static	void	background(void)
{
	t_object	*p;
	t_matrix	trans;
	t_matrix	rot;

	p = plane();
	p->material.color = white();
	p->material.ambient = 1;
	p->material.diffuse = 0;
	p->material.specular = 0;
	rotation_x(MY_PI / 2, &rot);
	translation(vector(0, 0, 500), &trans);
	mx_product(trans, rot, &p->transform);
	create_object(p);
}

static void	add_sphere(void)
{
	t_object	*s;

	s = sphere();
	s->material.color = tcolor(0.373, 0.404, 0.550);
	s->material.ambient = 0.2;
	s->material.specular = 1.0;
	s->material.shininess = 200;
	s->material.reflective = 0.7;
	s->material.transparency = 0.7;
	s->material.refractive_index = 1.5;
	large_object(&s->transform);
	create_object(s);
}

static void	add_cubes(void)
{
	t_object	*c;
	t_matrix	trans;
	t_matrix	size;

	c = cube();
	c->material = white_material();
	translation(vector(4, 0, 0), &trans);
	medium_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = blue_material();
	translation(vector(8.5, 1.5, -0.5), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = red_material();
	translation(vector(0, 0, 4), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(4, 0, 4), &trans);
	small_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = purple_material();
	translation(vector(7.5, 0.5, 4), &trans);
	medium_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(-0.25, 0.25, 8), &trans);
	medium_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = blue_material();
	translation(vector(4, 1, 7.5), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = red_material();
	translation(vector(10, 2, 7.5), &trans);
	medium_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);
	
	c = cube();
	c->material = white_material();
	translation(vector(8, 2, 12), &trans);
	small_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(20, 1, 9), &trans);
	small_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = blue_material();
	translation(vector(-0.5, -5, 0.25), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = red_material();
	translation(vector(4, -4, 0), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(8.5, -4, 0), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(0, -4, 4), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = purple_material();
	translation(vector(-0.5, -4.5, 8), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(0, -8, 4), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);

	c = cube();
	c->material = white_material();
	translation(vector(-0.5, -8.5, 8), &trans);
	large_object(&size);
	mx_product(trans, size, &c->transform);
	create_object(c);
}

static void create_world_objects(void)
{
	background();
	add_sphere();
	add_cubes();
	set_light(point(50, 100, -50), 1.0);
	set_ambient_light(1.0, white_rgb());
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(100, 100, 0.785);
	view.from = point(-6, 6,  -10);
	view.to = point(6, 0, 6);
	view.up = vector(-0.45, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	book_cover(void)
{
	create_world_objects();
	create_world_camera();
	render();
	mlx_save_img_to_ppm(image(), "book_cover.ppm");
}
