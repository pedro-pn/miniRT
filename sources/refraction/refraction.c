/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refraction.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 18:47:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 20:48:39 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	snell_law(t_comp *comps)
{
	comps->n_ratio = comps->n1 / comps->n2;
	comps->cos_i = dotp(comps->eyev, comps->normalv);
	comps->sin2_t = pow(comps->n_ratio, 2) * (1 - pow(comps->cos_i, 2));
	comps->cos_t = sqrt(1.0 - comps->sin2_t);
}

t_c3d	refracted_color(t_comp comps, int remaining)

{
	t_c3d	result;
	t_v3d	direction;
	t_ray	refract_ray;

	snell_law(&comps);
	if (comps.object->material.transparency == 0 || remaining == 0
		|| comps.sin2_t > 1)
		return (black());
	direction = sub(scalar_times(comps.n_ratio * comps.cos_i - comps.cos_t,
				comps.normalv), scalar_times(comps.n_ratio, comps.eyev));
	refract_ray = ray(comps.under_point, direction);
	result = scalar_times(comps.object->material.transparency,
			color_at(refract_ray, remaining - 1));
	return (result);
}
