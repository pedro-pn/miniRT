/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teapot.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 00:35:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 11:13:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	create_wavefront_object(void)
{
	int			fd;
	t_parser	parser;
	t_group		*g;

	fd = open("./sources/demos/teapot.obj", O_RDONLY);
	parser = parser_obj_file(fd);
	g = obj_to_group(parser);
	clean_parser(&parser);
	create_object(g);
}

static void create_world_objects(void)
{
	create_wavefront_object();
	point_light(point(0, -1, -25), tcolor(1, 1, 1));
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(500, 500, MY_PI / 3);
	view.from = point(0, 4.0, -12);
	view.to = point(0, 1, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	teapot(void)
{
	create_world_camera();
	create_world_objects();
	divide(world()->objects->content, 1);
	render();
	mlx_save_img_to_ppm(image(), "teapot.ppm");
}
