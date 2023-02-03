/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/03 10:39:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_c3d	shade_hit(t_comp comps)
{
	t_lgt_param	params;
	t_c3d		surface_color;
	t_c3d		reflected;

	params.eyev = comps.eyev;
	params.normalv = comps.normalv;
	params.position = comps.over_point;
	params.in_shadow = is_shadowed(comps.over_point);
	surface_color = lighting(*comps.object, *light(), params);
	reflected = reflected_color(comps);
	return (add(surface_color, reflected));
}
