/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 15:55:58 by pedro             #+#    #+#             */
/*   Updated: 2023/05/03 20:43:38 by ppaulo-d         ###   ########.fr       */
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

void	add_bounding_box(t_box *dest, t_box src)
{
	add_point(dest, src.min);
	add_point(dest, src.max);
}

t_bool	box_contains_point(t_box box, t_p3d point)
{
	if (point.x < box.min.x || point.x > box.max.x)
		return (false);
	if (point.y < box.min.y || point.y > box.max.y)
		return (false);
	if (point.z < box.min.z || point.z > box.max.z)
		return (false);
	return (true);
}
