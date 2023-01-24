/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:20:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 14:20:10 by ppaulo-d         ###   ########.fr       */
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
	return (comps);
}
