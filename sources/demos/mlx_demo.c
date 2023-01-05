/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_demo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 13:22:46 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 17:52:19 by ppaulo-d         ###   ########.fr       */
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
	while (x < img->width)
	{
		y = 0;
		while (y < img->height)
		{
			mlx_draw_pixel(img, x, y, 255);
			y++;
		}
		x++;
	}
	// mlx_put_image_to_window(data()->mlx, data()->mlx_win, img->img, 0, 0);
	// mlx_loop(data()->mlx);
	mlx_save_img_to_ppm(img, "teste.ppm");
}
