/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 16:48:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 13:24:00 by ppaulo-d         ###   ########.fr       */
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

t_p3d	point(double x, double y, double z)
{
	return ((t_p3d)tuple_3d(x, y, z, 1));
}

t_v3d	vector(double x, double y, double z)
{
	return ((t_v3d)tuple_3d(x, y, z, 0));
}
