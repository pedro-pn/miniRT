/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/02 15:21:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/02 15:50:14 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// function reflected_color(world, comps)
// if comps.object.material.reflective = 0
// return color(0, 0, 0)
// end if
// reflect_ray ← ray(comps.over_point, comps.reflectv)
// color ← color_at(world, reflect_ray)
// return color * comps.object.material.reflective
// end function

t_c3d	reflected_color(t_comp comps)
{
	t_c3d	result;
	t_ray	reflected_ray;

	if (comps.object->material.reflective == 0.0)
		return (black());
	reflected_ray = ray(comps.over_point, comps.reflectv);
	result = color_at(reflected_ray);
	inspect_tuple(reflected_ray.origin, "ray origin: ");
	inspect_tuple(reflected_ray.direction, "ray direction: ");
	inspect_tuple(result, "color: ");

	printf("reflecive: %f\n", comps.object->material.reflective);
	return (scalar_times(comps.object->material.reflective, result));
}
