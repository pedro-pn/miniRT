/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/03 11:16:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_c3d	reflected_color(t_comp comps, int remaining)
{
	t_c3d	result;
	t_ray	reflected_ray;

	if (comps.object->material.reflective == 0.0 || remaining <= 0)
		return (black());
	reflected_ray = ray(comps.over_point, comps.reflectv);
	result = color_at(reflected_ray, remaining - 1);
	return (scalar_times(comps.object->material.reflective, result));
}
