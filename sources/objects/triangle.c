/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:16:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 20:50:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	calculate_triangle_normal(t_object *t)
{
	t->e1 = sub(t->p.p2, t->p.p1);
	t->e2 = sub(t->p.p3, t->p.p1);
	t->normalv = normalize(cross(t->e2, t->e1));
}

static t_bool	has_ray_missed(t_object *obj, t_tri_params *params, t_ray ray)
{
	params->dir_cross_e2 = cross(ray.direction, obj->e2);
	params->det = dotp(obj->e1, params->dir_cross_e2);
	if (fabs(params->det) < EPSILON)
		return (true);
	params->p1_to_origin = sub(ray.origin, obj->p.p1);
	params->f = 1.0 / params->det;
	params->u = params->f * dotp(params->p1_to_origin, params->dir_cross_e2);
	if (params->u < 0 || params->u > 1)
		return (true);
	params->origin_cross_e1 = cross(params->p1_to_origin, obj->e1);
	params->v = params->f * dotp(ray.direction, params->origin_cross_e1);
	if (params->v < 0 || (params->u + params->v) > 1)
		return (true);
	return (false);
}

t_intxs	intersect_triangle(t_object *obj, t_ray _ray)
{
	t_intxs			xs;
	t_ray			transformed_ray;
	t_tri_params	params;
	double			t;

	transformed_ray = ray_transf_inverse(obj->transform, _ray);
	xs = empty_intersection();
	if (has_ray_missed(obj, &params, transformed_ray))
		return (xs);
	t = params.f * dotp(obj->e2, params.origin_cross_e1);
	create_intersection(&xs, t, obj);
	if (obj->type == SMOOTH_TRIANGLE)
		intersect_with_uv(&xs, params.u, params.v);
	return (xs);
}

t_v3d	triangle_normal_at(t_object obj, t_p3d point, t_intx inter)
{
	(void)point;
	(void)inter;
	return (obj.normalv);
}

t_object	*triangle(t_tri_p p)
{
	t_object	*_triangle;

	_triangle = ft_calloc(1, sizeof(*_triangle));
	_triangle->type = TRIANGLE;
	mx_identity(&_triangle->transform);
	_triangle->material = material();
	_triangle->clean = free;
	_triangle->p = p;
	_triangle->normal = triangle_normal_at;
	_triangle->intersect = intersect_triangle;
	_triangle->bound_of = triangle_bounding_box;
	calculate_triangle_normal(_triangle);
	return (_triangle);
}
