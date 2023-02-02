/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:20:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/02 16:08:46 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_comp	prepare_computations(t_intx inter, t_ray ray)
{
	t_comp	comps;

	comps.t = inter.t;
	comps.object = inter.object;
	comps.point = position(comps.t, ray);
	comps.eyev = neg(ray.direction);
	comps.normalv = normal_at(*comps.object, comps.point);
	if (dotp(comps.eyev, comps.normalv) < 0)
	{
		comps.inside = true;
		comps.normalv = neg(comps.normalv);
	}
	else
		comps.inside = false;
	comps.over_point = add(comps.point, scalar_times(EPSILON, comps.normalv));
	comps.reflectv = reflect(ray.direction, comps.normalv);
	return (comps);
}

t_c3d	color_at(t_ray ray)
{
	t_intxs	xs;
	t_intx	*hit_inter;
	t_comp	comps;

	xs = intersect_world(ray);
	hit_inter = hit(xs);
	if (hit_inter == NULL)
	{
		ft_lstclear(&xs.intersections, free);
		return (tcolor(0.0, 0.0, 0.0));
	}
	comps = prepare_computations(*hit_inter, ray);
	ft_lstclear(&xs.intersections, free);
	return (shade_hit(comps));
}
