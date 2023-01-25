/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:17:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 23:34:29 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static unsigned char	tcolor_to_char(double color)
{
	if (color >= 1.0)
		return (COLOR_MAX);
	else if (color <= 0)
		return (COLOR_MIN);
	return ((unsigned char) (color * COLOR_MAX));
}

static double	char_to_tcolor(unsigned char color)
{
	return ((double) color / (double) COLOR_MAX);
}

t_rgb	tcolor_to_rgb(t_c3d color)
{
	t_rgb	color_rgb;

	color_rgb.r = tcolor_to_char(color.x);
	color_rgb.g = tcolor_to_char(color.y);
	color_rgb.b = tcolor_to_char(color.z);
	return (color_rgb);
}

t_c3d	rgb_to_tcolor(t_rgb rgb)
{
	t_c3d	color;

	color.x = char_to_tcolor(rgb.r);
	color.y = char_to_tcolor(rgb.g);
	color.z = char_to_tcolor(rgb.b);
	return (color);
}
