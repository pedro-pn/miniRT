/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:29:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 17:46:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

void	mlx_draw_pixel(t_mlx_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	*(unsigned int *)dst = color;
}

int	mlx_get_pixel_from_img(t_mlx_img *img, int x, int y)
{
	char	*pixel;

	pixel = img->addr + (y * img->line_length + x * img->bits_per_pixel / 8);
	return (*((unsigned int *)pixel));
}
