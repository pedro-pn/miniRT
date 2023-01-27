/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 23:08:40 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 23:39:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	is_shadowed(t_p3d point)
{
	t_ray	shadow_ray;
	t_v3d	shadow_vector;
	double	light_distance;
	t_intxs	xs;
	t_intx	*inter;

	shadow_vector = sub(light()->position, point);
	light_distance = magnitude(shadow_vector);
	shadow_ray = ray(point, normalize(shadow_vector));
	xs = intersect_world(shadow_ray);
	inter = hit(xs);
	if (inter == NULL)
	{
		ft_lstclear(&xs.intersections, free);
		return (false);
	}
	if (inter->t < light_distance)
	{
		ft_lstclear(&xs.intersections, free);
		return (true);
	}
	ft_lstclear(&xs.intersections, free);
	return (false);
}
