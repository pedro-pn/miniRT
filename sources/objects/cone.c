/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 18:31:57 by pedro             #+#    #+#             */
/*   Updated: 2023/04/04 19:47:47 by pedro            ###   ########.fr       */
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
	params.c = pow(ray.origin.x, 2)  - pow (ray.origin.y, 2)
		+ pow(ray.origin.z, 2);
	return (params);
}

static t_bool	check_cap(t_ray ray, double t, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= pow(y, 2));
}

static void	intersect_caps(t_object *cone, t_ray ray, t_intxs *xs)
{
	double	t;

	if (cone->closed == false || comp(ray.direction.y, 0))
		return;
	t = (cone->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cone->minimum))
		create_intersection(xs, t, cone);
	t = (cone->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cone->maximum))
		create_intersection(xs, t, cone);
}

t_intxs	intersect_cone(t_object *cone, t_ray ray)
{
	t_intxs	xs;
	t_quad	quad;
	t_quad_param params;
	
	xs = empty_intersection();
	ray = ray_transf_inverse(cone->transform, ray);
	params = cone_params(ray);
	quad = quadratic(params);
	intersect_caps(cone, ray, &xs);
	if (comp(params.a, 0.0) && comp(params.b, 0.0))
		return (xs);
	if (quad.det < 0)
		return (xs);
	if (comp(params.a, 0.0))
		create_intersection(&xs, -params.c/(2 * params.b), cone);
	if (check_valid_intersection(*cone, ray, quad.root_b))
		create_intersection(&xs, quad.root_b, cone);
	if (check_valid_intersection(*cone, ray, quad.root_a))
		create_intersection(&xs, quad.root_a, cone);
	return (xs);
}	

t_object	*cone(void)
{
	t_object	*_cone;

	_cone = ft_calloc(1, sizeof(*_cone));
	_cone->material = material();
	mx_identity(&_cone->transform);
	_cone->intersect = intersect_cone;
	// _cone->normal = cone_normal_at;
	_cone->maximum = __DBL_MAX__;
	_cone->minimum = -__DBL_MAX__;
	_cone->closed = false;
	return (_cone);
}
