/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:29:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 14:43:14 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_init(void)
{
	t_mlx_img	*_img;

	_img = image();
	_img->img = mlx_new_image(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	_img->width = SCREEN_WIDTH;
	_img->height = SCREEN_HEIGHT;
	_img->addr = mlx_get_data_addr(_img->img, &_img->bits_per_pixel,
			&_img->line_length, &_img->endian);
}

void	mlx_draw_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}
