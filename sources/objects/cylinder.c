/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/15 18:45:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_quad_param	cylinder_params(t_object *cylinder, t_ray ray)
{
	t_quad_param	params;

	ray = ray_transf_inverse(cylinder->transform, ray);
	params.a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	params.b = 2 * ray.origin.x * ray.direction.x +
		2 * ray.origin.z * ray.direction.z;
	params.c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	return (params);
}

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	t_intxs	xs;
	t_quad	quad;
	t_quad_param params;
	
	xs.intersections = NULL;
	params = cylinder_params(cylinder, ray);
	quad = quadratic(params);
	if (comp(params.a, 0.0))
		return (empty_intersection());
	if (quad.det < 0)
		return (empty_intersection());
	xs.count = 2;
	create_intersection(&xs.intersections, quad.root_b, cylinder);
	create_intersection(&xs.intersections, quad.root_a, cylinder);
	return (xs);
}

t_v3d	cylinder_normal_at(t_object object, t_p3d point)
{
	(void)object;
	return (vector(point.x, 0, point.z));
}

t_object	*cylinder(void)
{
	t_object	*_cylinder;

	_cylinder = ft_calloc(1, sizeof(*_cylinder));
	_cylinder->material = material();
	mx_identity(&_cylinder->transform);
	_cylinder->intersect = intersect_cylinder;
	_cylinder->normal = cylinder_normal_at;
	return (_cylinder);
}