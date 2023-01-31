/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ring.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:45:21 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 21:50:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	ring_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.patt_at = ring_at;
	return (patt);
}

t_c3d	ring_at(t_patt patt, t_p3d point)
{
	double	section;

	section = sqrt(pow(point.x, 2) + pow(point.z, 2));
	if ((int)floor(section) % 2 == 0)
		return(patt.a);
	return (patt.b);
}
