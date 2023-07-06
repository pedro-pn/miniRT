/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_teapot.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:35:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 15:30:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	create_wavefront_object(void)
{
	int			fd;
	t_parser	parser;
	t_group		*g;
	t_matrix	trans;
	t_matrix	rot_x;

	fd = open("./sources/demos/smooth_teapot.obj", O_RDONLY);
	parser = parser_obj_file(fd);
	g = obj_to_group(parser);
	rotation_x(- MY_PI / 2, &rot_x);
	translation(vector(0, -5, 0), &trans);
	mx_product(trans, rot_x, &g->transform);
	clean_parser(&parser);
	create_object(g);
}

static void create_world_objects(void)
{
	create_wavefront_object();
	point_light(point(0, 20, -15), tcolor(1, 1, 1));
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(500, 500, MY_PI / 3);
	view.from = point(0, 20, -20);
	view.to = point(0, 1, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	smooth_teapot(void)
{
	create_world_camera();
	create_world_objects();
	divide(world()->objects->content, 1);
	render();
	mlx_save_img_to_ppm(image(), "smooth_teapot.ppm");
}
