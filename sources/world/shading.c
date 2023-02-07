/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/07 20:14:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_c3d	sum_ref_colors(t_comp comps, int remaining)
{
	t_c3d		reflected;
	t_c3d		refracted;

	reflected = reflected_color(comps, remaining);
	refracted = refracted_color(comps, remaining);
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
