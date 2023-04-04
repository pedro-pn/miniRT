/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 20:47:45 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt.a = color_a;
	patt.b = color_b;
	patt.has_pattern = true;
	mx_identity(&patt.transform);
	return (patt);
}

t_c3d	pattern_at(t_object obj, t_p3d point)
{
	t_matrix	mx_inv;
	t_p3d		obj_point;
	t_p3d		patt_point;

	mx_inverse(obj.transform, &mx_inv);
	obj_point = mx_tuple_product(mx_inv, point);
	mx_inverse(obj.pattern.transform, &mx_inv);
	patt_point = mx_tuple_product(mx_inv, obj_point);
	return (obj.pattern.patt_at(obj.pattern, patt_point));
}
