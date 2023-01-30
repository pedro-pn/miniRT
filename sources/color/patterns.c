/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 12:29:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	stripe_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt.a = color_a;
	patt.b = color_b;
	patt.has_pattern = true;
	mx_identity(&patt.transform);
	return (patt);
}

t_c3d	stripe_at(t_patt patt, t_p3d point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (patt.a);
	return (patt.b);
}

t_c3d	stripe_at_object(t_object obj, t_p3d point)
{
	t_matrix	mx_inv;
	t_p3d		obj_point;
	t_p3d		patt_point;

	mx_inverse(obj.transform, &mx_inv);
	obj_point = mx_tuple_product(mx_inv,  point);
	mx_inverse(obj.pattern.transform, &mx_inv);
	patt_point = mx_tuple_product(mx_inv, obj_point);
	return (stripe_at(obj.pattern, patt_point));
}
