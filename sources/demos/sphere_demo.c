/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_demo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 15:47:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/09 18:07:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_intxs	*xs(void)
{
	static t_intxs	_xs;
	
	return (&_xs);
}

static t_sdemo	sdemo_init(int _width)
{
	t_sdemo	sdemo;

	sdemo._sphere = sphere();
	sdemo.wall_z = 10;
	sdemo.wall_size = 15;
	sdemo.pixel_size = sdemo.wall_size / _width;
	sdemo.half_wall = sdemo.wall_size / 2;
	sdemo.ray_origin = point(0, 0, -5);

	return (sdemo);
}

static t_intx	*cast_ray(t_sdemo sdemo)
{
	t_p3d	_point;
	t_ray	_ray;
	t_intxs	*_xs;

	_xs = xs();
	_point = point(sdemo.world_x, sdemo.world_y, sdemo.wall_z);
	_ray = ray(sdemo.ray_origin, normalize(sub(_point, sdemo.ray_origin)));
	*_xs = intersect_sphere(sdemo._sphere, _ray);
	return (hit(*_xs));
}

static void	draw_sdemo(t_mlx_img *img, t_sdemo sdemo)
{
	t_intx	*inter;
	int	x;
	int	y;

	x = 0;
	while (x < img->_width)
	{
		sdemo.world_x = sdemo.half_wall - sdemo.pixel_size * x;
		y = 0;
		while (y < img->_height)
		{
			sdemo.world_y = sdemo.half_wall - sdemo.pixel_size * y;
			inter = cast_ray(sdemo);
			if (inter != NULL)
			{
				ft_lstclear(&xs()->intersections, free);
				mlx_draw_pixel_rgb(img, x, y, color_rgb(255, 0, 0));
			}
			y++;
		}
		x++;
	}
}

void	sphere_demo(void)
{
	t_mlx_img	*img;
	t_sdemo		sdemo;

	set_camera(200, 200, MY_PI / 2);
	img = image();
	sdemo = sdemo_init(img->_width);
	draw_sdemo(img, sdemo);
	free(sdemo._sphere);
	mlx_save_img_to_ppm(img, "sphere.ppm");
}
