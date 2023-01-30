/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stripes.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 13:39:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	stripe_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt.a = color_a;
	patt.b = color_b;
	patt.has_pattern = true;
	patt.patt_at = stripe_at;
	mx_identity(&patt.transform);
	return (patt);
}

t_c3d	stripe_at(t_patt patt, t_p3d point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (patt.a);
	return (patt.b);
}
