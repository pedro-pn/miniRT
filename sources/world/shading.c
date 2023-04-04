/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 20:50:42 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_c3d	sum_ref_colors(t_comp comps, int remaining)
{
	t_c3d		reflected;
	t_c3d		refracted;
	double		reflectance;
	t_material	m;

	reflected = reflected_color(comps, remaining);
	refracted = refracted_color(comps, remaining);
	m = comps.object->material;
	if (m.reflective > 0 && m.transparency > 0)
	{
		reflectance = schlick(comps);
		return (add(scalar_times(reflectance, reflected),
				scalar_times(1 - reflectance, refracted)));
	}
	return (add(reflected, refracted));
}

t_c3d	shade_hit(t_comp comps, int remaining)
{
	t_lgt_param	params;
	t_c3d		surface_color;
	t_c3d		ref_color;

	params.eyev = comps.eyev;
	params.normalv = comps.normalv;
	params.position = comps.over_point;
	params.in_shadow = is_shadowed(comps.over_point);
	surface_color = lighting(*comps.object, *light(), params);
	ref_color = sum_ref_colors(comps, remaining);
	return (add(surface_color, ref_color));
}
