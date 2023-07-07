/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cylinder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:23:51 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:26:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_cylinder(t_object *cylinder, t_create_cylinder p)
{
	cylinder->minimum = -p.height / 2.0;
	cylinder->maximum = p.height / 2.0;
	cylinder->closed = true;
	cylinder->material.color = rgb_to_tcolor(p.color);
	translate_object(cylinder, p.origin);
	fast_rotate_object(cylinder, p.normal);
	scale_object(cylinder, vector(p.diameter / 2, 1, p.diameter / 2));
}

void	create_cylinder(t_create_cylinder params)
{
	t_object	*_cylinder;

	_cylinder = cylinder();
	set_cylinder(_cylinder, params);
	create_object(_cylinder);
}
