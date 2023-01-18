/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:10 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/18 16:29:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	normal_at(t_object obj, t_p3d _point)
{
	t_matrix	transpose;
	t_matrix	inverse;
	t_v3d		normal;

	mx_inverse(obj.transform, &inverse);
	_point = mx_tuple_product(inverse, _point);
	normal = sub(_point, obj.origin);
	mx_transpose(inverse, &transpose);
	normal = mx_tuple_product(transpose, normal);
	normal.w = 0;
	return (normalize(normal));
}
