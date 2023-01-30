/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:55:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 12:31:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_c3d	shade_hit(t_comp comps)
{
	t_lgt_param	params;

	params.eyev = comps.eyev;
	params.normalv = comps.normalv;
	params.position = comps.over_point;
	params.in_shadow = is_shadowed(comps.over_point);
	return (lighting(*comps.object, *light(), params));
}
