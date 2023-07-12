/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cone.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:42:10 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/12 12:09:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_cone(t_object *cone, t_create_cone p)
{
	cone->minimum = -1;
	cone->maximum = 0;
	cone->closed = true;
	cone->material.color = rgb_to_tcolor(p.color);
	p.origin.y += p.height / 2.0;
	translate_object(cone, p.origin);
	fast_rotate_object(cone, p.normal);
	scale_object(cone, vector(p.diameter / 2.0, p.height, p.diameter / 2.0));
}

void	create_cone(t_create_cylinder params)
{
	t_object	*_cone;

	_cone = cone();
	set_cone(_cone, params);
	create_object(_cone);
}
