/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:55:58 by pedro             #+#    #+#             */
/*   Updated: 2023/04/13 16:20:11 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	empty_bounding_box(void)
{
	t_box	box;

	box.min = point(__DBL_MAX__, __DBL_MAX__, __DBL_MAX__);
	box.max = point(-__DBL_MAX__, -__DBL_MAX__, -__DBL_MAX__);
	return (box);
}

t_box	bounding_box(t_p3d min, t_p3d max)
{
	t_box	box;

	box.min = min;
	box.max = max;
	return (box);
}

void	add_point(t_box *box, t_p3d point)
{
	if (point.x < box->min.x)
		box->min.x = point.x;
	if (point.y < box->min.y)
		box->min.y = point.y;
	if (point.z < box->min.z)
		box->min.z = point.z;
	if (point.x > box->max.x)
		box->max.x = point.x;
	if (point.y > box->max.y)
		box->max.y = point.y;
	if (point.z > box->max.z)
		box->max.z = point.z;
}
