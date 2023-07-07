/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_set.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:42:04 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 11:48:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_ambient_light(char *line)
{
	double	brightness;
	t_rgb	color;

	line = skip_field(line);
	brightness = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	set_ambient_light(brightness, color);
}

void	parse_camera(char *line)
{
	t_p3d	origin;
	t_v3d	orientation;
	double	horz_fov_deg;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	orientation = parse_vector(line);
	line = skip_field(line);
	horz_fov_deg = ft_atof(line);
	set_scene_camera(origin, orientation, horz_fov_deg);
}

void	parse_light(char *line)
{
	t_p3d	origin;
	double	brightness;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	brightness = ft_atof(line);
	set_light(origin, brightness);
}
