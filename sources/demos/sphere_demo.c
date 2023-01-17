/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_demo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:47:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/17 16:22:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	sphere_demo(void)
{
	t_mlx_img	*img;
	t_ray		_ray;
	t_object	*_sphere;
	t_p3d		_point;
	double		wall_size;
	double		wall_z;
	double		pixel_size;
	double		half_wall;
	int			x;
	int			y;
	double		world_x;
	double		world_y;
	t_p3d		ray_origin;
	t_intxs		xs;
	t_intx		*inter;


	img = image();
	_sphere = sphere();
	wall_z = 10;
	wall_size = 15;
	pixel_size = wall_size / img->_width;
	half_wall = wall_size / 2;
	x = 0;
	ray_origin = point(0, 0, -5);
	while (x < img->_width)
	{
		world_x = half_wall - pixel_size * x;
		y = 0;
		while (y < img->_height)
		{
			world_y = half_wall - pixel_size * y;
			_point = point(world_x, world_y, wall_z);
			_ray = ray(ray_origin, normalize(sub(_point, ray_origin)));
			xs = intersect(_sphere, _ray);
			inter = hit(xs);
			if (inter != NULL)
				mlx_draw_pixel_rgb(img, x, y, _sphere->color);
			else
				mlx_draw_pixel_rgb(img, x, y, color_rgb(255, 255, 255));
			y++;
		}
		x++;
	}
	mlx_save_img_to_ppm(img, "sphere.ppm");
}
