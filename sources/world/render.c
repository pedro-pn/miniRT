/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 00:22:40 by ppaulo-d         ###   ########.fr       */
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
			color = tcolor_to_rgb(color_at(_ray, 4));
			draw_pixel_rgb(buffer(), x, y, color);
			y++;
		}
		x++;
		print_progress(x, y);
	}
}
