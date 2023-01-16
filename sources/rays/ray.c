/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 13:54:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/16 16:47:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	ray(t_p3d origin, t_v3d direction)
{
	t_ray	_ray;

	_ray.origin = origin;
	_ray.direction = direction;
	return (_ray);
}

t_p3d	position(double scalar, t_ray _ray)
{
	t_v3d	direction;

	direction = scalar_times(scalar, _ray.direction);
	return (add(_ray.origin, direction));
}