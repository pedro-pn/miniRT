/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:40:01 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 13:45:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_ambient_light(double brightness, t_rgb color)
{
	t_c3d	intensity;

	world()->ambient_light.brightness = brightness;
	world()->ambient_light.color_rgb = color;
	intensity = scalar_times(brightness, rgb_to_tcolor(color));
	world()->ambient_light.intensity = intensity;
}
