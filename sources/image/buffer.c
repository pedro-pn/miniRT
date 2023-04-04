/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:55:12 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 00:24:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	draw_pixel(t_buffer *buffer, int x, int y, int color)
{
	char	*dst;

	dst = buffer->img + (y * buffer->line_length + x * 32 / 8);
	*(unsigned int *)dst = color;
}

void	draw_pixel_rgb(t_buffer *buffer, int x, int y, t_rgb color_rgb)
{
	draw_pixel(buffer, x, y, get_rgb_color(color_rgb));
}

int	get_pixel_from_buffer(t_buffer *buffer, int x, int y)
{
	char	*pixel;

	pixel = buffer->img + (y * buffer->line_length + x * 32 / 8);
	return (*((unsigned int *)pixel));
}

void	buffer_to_mlx_img(t_buffer *buffer, t_mlx_img *img)
{
	int	x;
	int	y;
	int	pixel;

	x = 0;
	while (x < buffer->_width)
	{
		y = 0;
		while (y < buffer->_height)
		{
			pixel = get_pixel_from_buffer(buffer, x, y);
			mlx_draw_pixel(img, x, y, pixel);
			y++;
		}
		x++;
	}
}