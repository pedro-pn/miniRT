/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:43:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

int	get_rgb_color(t_rgb rgb)
{
	return (get_color(rgb.r, rgb.g, rgb.b));
}

t_rgb	color_rgb(int _red, int _green, int _blue)
{
	return ((t_rgb){_red, _green, _blue});
}

t_rgb	int_to_rgb(int color)
{
	t_rgb	rgb;

	rgb.r = get_red(color);
	rgb.g = get_green(color);
	rgb.b = get_blue(color);
	return (rgb);
}
