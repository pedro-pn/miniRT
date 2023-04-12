/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/11 21:12:35 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_quad_param	cylinder_params(t_ray ray)
{
	t_quad_param	params;

	params.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	params.b = 2 * ray.origin.x * ray.direction.x
		+ 2 * ray.origin.z * ray.direction.z;
	params.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	return (params);
}

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	t_intxs			xs;
	t_quad			quad;
	t_quad_param	params;

	xs = empty_intersection();
	ray = ray_transf_inverse(cylinder->transform, ray);
	params = cylinder_params(ray);
	quad = quadratic(params);
	intersect_cy_caps(cylinder, ray, &xs);
	if (comp(params.a, 0.0) == true)
		return (xs);
	if (quad.det < 0)
		return (xs);
	if (check_valid_intersection(*cylinder, ray, quad.root_b))
		create_intersection(&xs, quad.root_b, cylinder);
	if (check_valid_intersection(*cylinder, ray, quad.root_a))
		create_intersection(&xs, quad.root_a, cylinder);
	return (xs);
}

t_v3d	cylinder_normal_at(t_object object, t_p3d point)
{
	double	dist;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < 1 && point.y >= object.maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && point.y <= object.minimum + EPSILON)
		return (vector(0, -1, 0));
	return (vector(point.x, 0, point.z));
}

t_object	*cylinder(void)
{
	t_object	*_cylinder;

	_cylinder = ft_calloc(1, sizeof(*_cylinder));
	_cylinder->type = CYLINDER;
	_cylinder->material = material();
	mx_identity(&_cylinder->transform);
	_cylinder->intersect = intersect_cylinder;
	_cylinder->normal = cylinder_normal_at;
	_cylinder->maximum = __DBL_MAX__;
	_cylinder->minimum = -__DBL_MAX__;
	_cylinder->closed = false;
	_cylinder->clean = free;
	return (_cylinder);
}
