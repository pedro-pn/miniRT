/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_demo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/07 14:40:25 by ppaulo-d         ###   ########.fr       */
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
	t_mlx_img	*img;
	int			x;
	int			y;
	int			x2;
	double		_red;
	double		_green;

	img = image();
	x = 0;
	x2 = x;
	while (x < img->_width)
	{
		y = img->_height - 1;
		x2 = 0;
		while (y > 0)
		{
			_red = (double) x / (img->_width - 1);
			_green = (double) y / (img->_height - 1);
			mlx_draw_pixel_rgb(img, x, x2, color_rgb(_red * 255.999, _green * 255.999, 0.25 * 255.999));
			y--;
			x2++;
		}
		x++;
	}
	// mlx_put_image_to_window(data()->mlx, data()->mlx_win, img->img, 0, 0);
	// mlx_loop(data()->mlx);
	mlx_save_img_to_ppm(img, "teste2.ppm");
}
