/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:10:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 12:31:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*smooth_triangle(t_tri_p p, t_tri_n n)
{
	t_object	*_triangle;

	_triangle = ft_calloc(1, sizeof(*_triangle));
	_triangle->type = SMOOTH_TRIANGLE;
	mx_identity(&_triangle->transform);
	_triangle->material = material();
	_triangle->clean = free;
	_triangle->p = p;
	_triangle->n = n;
	_triangle->intersect = intersect_triangle;
	_triangle->bound_of = triangle_bounding_box;
	calculate_triangle_normal(_triangle);
	return (_triangle);
}
