/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox_bhv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:25:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/23 16:50:28 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_boxd	get_box_dimensions(t_box box)
{
	t_boxd	boxd;

	boxd.dx = box.max.x - box.min.x;
	boxd.dy = box.max.y - box.min.y;
	boxd.dz = box.max.z - box.min.z;
	return (boxd);
}

static double	get_greatest_box_dimension(t_boxd boxd)
{
	double	greatest;

	greatest = boxd.dx;
	if (greatest < boxd.dy)
		greatest = boxd.dy;
	if (greatest < boxd.dz)
		greatest = boxd.dz;
	return (greatest);
}

static void	divide_plane(double *x0, double *x1, double dx)
{
	*x0 = *x0 + dx / 2.0;
	*x1 = *x0;
}

t_sbox	split_bounds(t_box box)
{
	t_sbox	sbox;
	t_boxd	boxd;
	t_box	mid;
	double	greatest;

	mid = box;
	boxd = get_box_dimensions(box);
	greatest = get_greatest_box_dimension(boxd);
	if (greatest == boxd.dx)
		divide_plane(&mid.min.x, &mid.max.x, boxd.dx);
	else if (greatest == boxd.dy)
		divide_plane(&mid.min.y, &mid.max.y, boxd.dy);
	else
		divide_plane(&mid.min.z, &mid.max.z, boxd.dz);
	sbox.left = bounding_box(box.min, mid.max);
	sbox.right = bounding_box(mid.min, box.max);
	return (sbox);
}
