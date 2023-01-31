/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uv_checkers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 12:40:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/31 13:57:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	sphere_checkers(double wdt, double hgt, t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.width = wdt;
	patt.height = hgt;
	patt.patt_at = sphere_checkers_at;
	return (patt);
}

t_c3d	sphere_checkers_at(t_patt patt, t_p3d point)
{
	t_p3d	uv_point;
	double	u2;
	double	v2;

	uv_point = spherical_map(point);
	u2 = floor(uv_point.x * patt.width);
	v2 = floor(uv_point.y * patt.height);
	if ((int)(u2 + v2) % 2 == 0)
		return (patt.a);
	return (patt.b);
}

t_p3d	spherical_map(t_p3d	_point)
{
	t_p3d	result;
	double	theta;
	double	radius;
	double	phi;
	double	raw_u;

	theta = atan2(_point.x, _point.z);
	radius = magnitude(vector(_point.x, _point.y, _point.z));
	phi = acos(_point.y / radius);
	raw_u = theta / (2 * MY_PI);
	result.x = 1 - (raw_u + 0.5);
	result.y = 1 - phi / MY_PI;
	return (point(result.x, result.y, 0));
}
