/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 13:18:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 13:46:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_c3d	pattern_at_object(t_object obj, t_p3d point)
{
	t_matrix	mx_inv;
	t_p3d		obj_point;
	t_p3d		patt_point;

	mx_inverse(obj.transform, &mx_inv);
	obj_point = mx_tuple_product(mx_inv,  point);
	mx_inverse(obj.pattern.transform, &mx_inv);
	patt_point = mx_tuple_product(mx_inv, obj_point);
	return (obj.pattern.patt_at(obj.pattern, patt_point));
}
