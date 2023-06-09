/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:31:57 by pedro             #+#    #+#             */
/*   Updated: 2023/06/08 23:17:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_quad_param	cone_params(t_ray ray)
{
	t_quad_param	params;

	params.a = pow(ray.direction.x, 2) - pow(ray.direction.y, 2)
		+ pow(ray.direction.z, 2);
	params.b = 2 * ray.origin.x * ray.direction.x
		- 2 * ray.origin.y * ray.direction.y
		+ 2 * ray.origin.z * ray.direction.z;
	params.c = pow(ray.origin.x, 2) - pow (ray.origin.y, 2)
		+ pow(ray.origin.z, 2);
	return (params);
}

t_intxs	intersect_cone(t_object *cone, t_ray ray)
{
	t_intxs			xs;
	t_quad			quad;
	t_quad_param	params;

	xs = empty_intersection();
	ray = ray_transf_inverse(cone->transform, ray);
	params = cone_params(ray);
	quad = quadratic(params);
	intersect_cone_caps(cone, ray, &xs);
	if (comp(params.a, 0.0) && comp(params.b, 0.0))
		return (xs);
	if (quad.det < 0)
		return (xs);
	if (comp(params.a, 0.0))
		create_intersection(&xs, -params.c / (2 * params.b), cone);
	if (check_valid_intersection(*cone, ray, quad.root_b))
		create_intersection(&xs, quad.root_b, cone);
	if (check_valid_intersection(*cone, ray, quad.root_a))
		create_intersection(&xs, quad.root_a, cone);
	return (xs);
}	

t_v3d	cone_normal_at(t_object object, t_p3d point)
{
	double	dist;
	double	y;

	dist = pow(point.x, 2) + pow(point.z, 2);
	if (dist < pow(object.maximum, 2) && point.y >= object.maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < pow(object.minimum, 2)
		&& point.y <= object.minimum + EPSILON)
		return (vector(0, -1, 0));
	y = sqrt(pow(point.x, 2) + pow(point.z, 2));
	if (point.y > 0)
		y = -y;
	return (vector(point.x, y, point.z));
}

t_object	*cone(void)
{
	t_object	*_cone;

	_cone = ft_calloc(1, sizeof(*_cone));
	_cone->type = CONE;
	_cone->material = material();
	mx_identity(&_cone->transform);
	_cone->intersect = intersect_cone;
	_cone->normal = cone_normal_at;
	_cone->bound_of = cone_bounding_box;
	_cone->maximum = __DBL_MAX__;
	_cone->minimum = -__DBL_MAX__;
	_cone->closed = false;
	_cone->clean = free;
	_cone->group = NULL;
	return (_cone);
}
