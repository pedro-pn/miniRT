/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radial.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 10:54:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/01 11:03:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	radial_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.patt_at = radial_at;
	return (patt);
}

t_c3d	radial_at(t_patt patt, t_p3d point)
{
	t_c3d	distance;
	double	fraction;
	double	section;

	distance = sub(patt.b, patt.a);
	section = sqrt(pow(point.x, 2) + pow(point.z, 2));
	fraction = section - floor(section);
	return (add(patt.a, scalar_times(fraction, distance)));
}
