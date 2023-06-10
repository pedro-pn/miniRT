/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:16:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/10 20:43:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calculate_triangle_normal(t_object *t)
{
	t->e1 = sub(t->p2, t->p1);
	t->e2 = sub(t->p3, t->p1);
	t->normalv = normalize(cross(t->e2, t->e1));
}

t_intxs	intersect_triangle(t_object *obj, t_ray _ray)
{
	t_intxs	xs;
	t_v3d	origin_cross_e1;
	t_v3d	dir_cross_e2;
	t_v3d	p1_to_origin;
	double	det;
	double	f;
	double	u;
	double	v;
	double	t;

	xs = empty_intersection();
	dir_cross_e2 = cross(_ray.direction, obj->e2);
	det = dotp(obj->e1, dir_cross_e2);
	if (fabs(det) < EPSILON)
		return (xs);
	p1_to_origin = sub(_ray.origin, obj->p1);
	f = 1.0 / det;
	u = f * dotp(p1_to_origin, dir_cross_e2);
	if (u < 0 || u > 1)
		return (xs);
	origin_cross_e1 = cross(p1_to_origin, obj->e1);
	v = f * dotp(_ray.direction, origin_cross_e1);
	if (v < 0 || (u + v) > 1) 
		return (xs);
	t = f * dotp(obj->e2, origin_cross_e1);
	create_intersection(&xs, t, obj);
	return (xs);
}

t_v3d	triangle_normal_at(t_object obj, t_p3d point)
{
	(void)point;
	return (obj.normalv);
}

t_object	*triangle(t_p3d p1, t_p3d p2, t_p3d p3)
{
	t_object	*_triangle;

	_triangle = ft_calloc(1, sizeof(*_triangle));
	_triangle->type = TRIANGLE;
	mx_identity(&_triangle->transform);
	_triangle->material = material();
	_triangle->clean = free;
	_triangle->p1 = p1;
	_triangle->p2 = p2;
	_triangle->p3 = p3;
	_triangle->normal = triangle_normal_at;
	_triangle->intersect = intersect_triangle;
	calculate_triangle_normal(_triangle);
	return (_triangle);
}
