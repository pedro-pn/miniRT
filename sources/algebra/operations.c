/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:17:44 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/09 22:43:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_t3d	add(t_t3d t1, t_t3d t2)
{
	t_t3d	result;

	result.x = t1.x + t2.x;
	result.y = t1.y + t2.y;
	result.z = t1.z + t2.z;
	result.w = t1.w + t2.w;
	return (result);
}

t_t3d	sub(t_t3d t1, t_t3d t2)
{
	t_t3d	result;

	result.x = t1.x - t2.x;
	result.y = t1.y - t2.y;
	result.z = t1.z - t2.z;
	result.w = t1.w - t2.w;
	return (result);
}

t_t3d	neg(t_t3d tuple)
{
	return ((t_t3d){-tuple.x, -tuple.y, -tuple.z, -tuple.w});
}

t_t3d	scalar_times(double scalar, t_t3d tuple)
{
	t_t3d	result;

	result.x = scalar * tuple.x;
	result.y = scalar * tuple.y;
	result.z = scalar * tuple.z;
	result.w = scalar * tuple.w;
	return (result);
}

t_t3d	scalar_div(double scalar, t_t3d tuple)
{
	t_t3d	result;

	result.x = tuple.x / scalar;
	result.y = tuple.y / scalar;
	result.z = tuple.z / scalar;
	result.w = tuple.w / scalar;
	return (result);
}
