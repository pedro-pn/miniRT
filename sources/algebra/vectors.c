/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:05:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 11:17:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"
#include <math.h>

double	magnitude(t_v3d vector)
{
	vector.x = vector.x * vector.x;
	vector.y = vector.y * vector.y;
	vector.z = vector.z * vector.z;
	vector.w = vector.w * vector.w;
	return (sqrt(vector.x + vector.y + vector.z + vector.w));
}

t_v3d	normalize(t_v3d vector)
{
	double	mag;

	mag = magnitude(vector);
	vector.x = vector.x / mag;
	vector.y = vector.y / mag;
	vector.z = vector.z / mag;
	vector.w = vector.w / mag;
	return (vector);
}

double	dotp(t_v3d v1, t_v3d v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z + v1.w * v2.w);
}

t_v3d	cross(t_v3d v1, t_v3d v2)
{
	t_v3d	product;

	product.x = v1.y * v2.z - v1.z * v2.y;
	product.y = v1.z * v2.x - v1.x * v2.z;
	product.z = v1.x * v2.y - v1.y * v2.x;
	product.w = 0;
	return (product);
}
