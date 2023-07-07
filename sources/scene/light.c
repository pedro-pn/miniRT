/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:45:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:59:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	create_point_light(t_p3d position, double brightness, t_rgb color_rgb)
{
	t_light	new_light;

	new_light.position = position;
	new_light.brightness = brightness;
	new_light.color_rgb = color_rgb;
	new_light.color_3d = rgb_to_tcolor(color_rgb);
	new_light.intensity = scalar_times(brightness, new_light.color_3d);
	return (new_light);
}


void	set_light(t_p3d origin, double brightness)
{
	t_light	_light;

	_light = create_point_light(origin, brightness, white_rgb());
	world()->light = _light;
}
