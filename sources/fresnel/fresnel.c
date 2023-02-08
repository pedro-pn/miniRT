/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fresnel.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 11:40:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/08 12:04:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	schlick(t_comp comps)
{
	double	reflectance;
	double	result;
	double	cos;

	snell_law(&comps);
	cos = comps.cos_i;
	if (comps.n1 > comps.n2)
	{
		if (comps.sin2_t > 1)
			return (1.0);
		cos = comps.cos_t;
	}
	reflectance = ((comps.n1 - comps.n2) / (comps.n1 + comps.n2));
	reflectance *= reflectance;
	result = reflectance + (1 - reflectance) * pow(1 - cos, 5);
	return (result);
}
