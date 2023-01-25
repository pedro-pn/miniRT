/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 22:51:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_p3d origin, t_v3d direction)
{
	t_ray	_ray;

	_ray.origin = origin;
	_ray.direction = direction;
	return (_ray);
}

t_p3d	position(double scalar, t_ray _ray)
{
	t_v3d	direction;

	direction = scalar_times(scalar, _ray.direction);
	return (add(_ray.origin, direction));
}

t_ray	ray_for_pixel(int x, int y)
{
	t_camera	cam;
	double		xoffset;
	double		yoffset;
	double		world_x;
	double		world_y;
	t_p3d		pixel;
	t_p3d		origin;
	t_v3d		direction;
	t_matrix	mx_inv;

	cam = *camera();
	xoffset = ((double) x + 0.5) * cam.pixel_size;
	yoffset = ((double) y + 0.5) * cam.pixel_size;
	world_x = cam.half_width - xoffset;
	world_y = cam.half_height - yoffset;
	mx_inverse(cam.transform, &mx_inv);
	pixel = mx_tuple_product(mx_inv, point(world_x, world_y, -1));
	origin = mx_tuple_product(mx_inv, point(0, 0, 0));
	direction = normalize(sub(pixel, origin));
	return (ray(origin, direction));
}
