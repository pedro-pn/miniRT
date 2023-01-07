/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:29:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/06 18:55:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	mlx_draw_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

void	mlx_draw_pixel_rgb(t_mlx_img *img, int x, int y, t_rgb color_rgb)
{
	mlx_draw_pixel(img, x, y, get_rgb_color(color_rgb));
}

int	mlx_get_pixel_from_img(t_mlx_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*((unsigned int *)pixel));
}
