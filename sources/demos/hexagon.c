/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexagon.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 19:00:17 by pedro             #+#    #+#             */
/*   Updated: 2023/07/07 14:19:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_object	*hexagon_corner(void) {
	t_object	*corner;
	t_matrix	scal;
	t_matrix	trans;
	
	corner = sphere();
	translation(vector(0, 0, -1), &trans);
	scaling(vector(0.25, 0.25, 0.25), &scal);
	mx_product(trans, scal, &corner->transform);
	return (corner);
}

static t_object	*hexagon_edge(void) {
	t_object	*edge;
	t_matrix	trans;
	t_matrix	rot_y;
	t_matrix	rot_z;
	t_matrix	scal;
	t_matrix	mx;
	t_matrix	mx2;
	
	
	edge = cylinder();
	edge->closed = true;
	edge->minimum = 0;
	edge->maximum = 1;
	translation(vector(0, 0, -1), &trans);
	rotation_y(-MY_PI / 6, &rot_y);
	rotation_z(-MY_PI / 2, &rot_z);
	scaling(vector(0.25, 1, 0.25), &scal);
	mx_product(trans, rot_y, &mx);
	mx_product(mx, rot_z, &mx2);
	mx_product(mx2, scal, &edge->transform);
	return (edge);
}

static t_group	*hexagon_side(void) {
	t_group	*side;
	
	side = group();
	add_child(side, hexagon_corner());
	add_child(side, hexagon_edge());
	return (side);
}

static	void	hexagon(void) {
	t_group	*hexagon;
	t_group	*side;
	
	hexagon = group();
	for (int i = 0; i < 6; i++) {
		side = hexagon_side();
		rotation_y(i * MY_PI / 3, &side->transform);
		add_child(hexagon, side);
	}
	create_object(hexagon);
}

static void create_world_objects(void)
{
	hexagon();
	set_light(point(-10, 10, -10), 1.0);
	set_ambient_light(1.0, white_rgb());
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(10, 10, MY_PI / 3);
	view.from = point(0, 1.5, -5);
	view.to = point(0, 1, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	hexagon_demo(void)
{
	create_world_objects();
	create_world_camera();
	render();
	mlx_save_img_to_ppm(image(), "hexagon.ppm");
}
