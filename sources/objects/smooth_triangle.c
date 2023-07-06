/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smooth_triangle.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 12:10:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 20:52:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_with_uv(t_intxs *xs, double u, double v)
{
	t_intx	*inter;

	inter = xs->intersections->content;
	inter->u = u;
	inter->v = v;
}

t_v3d	smooth_triangle_normal_at(t_object obj, t_p3d point, t_intx inter)
{
	t_v3d	normal;
	t_v3d	aux_vector_1;
	t_v3d	aux_vector_2;
	t_v3d	aux_vector_3;

	(void)point;
	aux_vector_1 = scalar_times(inter.u, obj.n.n2);
	aux_vector_2 = scalar_times(inter.v, obj.n.n3);
	aux_vector_3 = scalar_times((1 - inter.u - inter.v), obj.n.n1);
	normal = add(aux_vector_1, aux_vector_2);
	normal = add(normal, aux_vector_3);
	return (normal);
}

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
	_triangle->normal = smooth_triangle_normal_at;
	_triangle->intersect = intersect_triangle;
	_triangle->bound_of = triangle_bounding_box;
	calculate_triangle_normal(_triangle);
	return (_triangle);
}
