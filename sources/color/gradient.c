/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gradient.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 14:47:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 15:02:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	gradient_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.patt_at = gradient_at;
	return (patt);
}

t_c3d	gradient_at(t_patt patt, t_p3d point)
{
	t_c3d	distance;
	double	fraction;

	distance = sub(patt.b, patt.a);
	fraction = point.x - floor(point.x);
	return (add(patt.a, scalar_times(fraction, distance)));
}
