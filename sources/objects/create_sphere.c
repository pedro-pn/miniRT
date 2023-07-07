/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_sphere.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:06:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:17:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_sphere(t_object *sphere,
				t_p3d origin, double diameter, t_rgb color)
{
	sphere->diameter = diameter;
	sphere->radius = diameter / 2.0;
	sphere->material.color = rgb_to_tcolor(color);
	translate_object(sphere, origin);
}

void	create_sphere(t_p3d origin, double diameter, t_rgb color)
{
	t_object	*_sphere;

	_sphere = sphere();
	set_sphere(_sphere, origin, diameter, color);
	create_object(_sphere);
}
