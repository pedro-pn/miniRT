/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_demo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 12:11:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	mlx_demo(void)
{
	t_mlx_img	*img;
	int			x;
	int			y;

	img = image();
	x = 0;
	while (x < img->_width)
	{
		y = 0;
		while (y < img->_height)
		{
			mlx_draw_pixel(img, x, y, 255 << 16);
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(data()->mlx, data()->mlx_win, img->img, 0, 0);
	// mlx_loop(data()->mlx);
	mlx_save_img_to_ppm(img, "teste.ppm");
}

void	hello_world_img(void)
{
	int			x;
	int			y;
	int			x2;
	t_rgb		color;

	set_camera(200, 200, MY_PI / 2);
	x = image()->_width - 1;
	x2 = 0;
	color.b = 0.25 * 255.999;
	while (x > 0)
	{
		y = 0;
		while (y < image()->_height)
		{
			color.r = (double) y * 255.999/ (image()->_width - 1);
			color.g = (double) x * 255.999/ (image()->_height - 1);
			mlx_draw_pixel_rgb(image(), x2, y, color);
			y++;
		}
		x--;
		x2++;
	}
	mlx_save_img_to_ppm(image(), "teste4.ppm");
}
