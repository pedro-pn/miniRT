/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:48:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 14:23:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_t3d	tuple_3d(double x, double y, double z, double w)
{
	t_t3d	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_t3d	null_tuple(void)
{
	return ((t_t3d){0, 0, 0, 0});
}

t_p3d	point(double x, double y, double z)
{
	return ((t_p3d)tuple_3d(x, y, z, 1));
}

t_v3d	vector(double x, double y, double z)
{
	return ((t_v3d)tuple_3d(x, y, z, 0));
}

void	inspect_tuple(t_t3d tuple, const char *name)
{
	printf("%s: (%f, %f, %f, %f)\n", name, tuple.x, tuple.y, tuple.z, tuple.w);
}