/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/27 12:48:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render(void)
{
	t_ray		_ray;
	t_rgb		color;
	int			x;
	int			y;

	x = 0;
	while (x < camera()->hsize)
	{
		y = 0;
		while (y < camera()->vsize)
		{
			_ray = ray_for_pixel(x, y);
			color = tcolor_to_rgb(color_at(_ray));
			mlx_draw_pixel_rgb(image(), x, y, color);
			y++;
		}
		x++;
		print_progress(x, y);
	}
}
