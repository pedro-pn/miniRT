/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/09 12:18:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	t_quad	params;
	t_intxs	xs;
	
	xs.intersections = NULL;
	ray = ray_transf_inverse(cylinder->transform, ray);
	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (comp(a, 0.0))
		return (empty_intersection());
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2) - 1;
	disc = discriminant(a, b, c);
	if (disc < 0)
		return (empty_intersection());
	params = quadratic(a, b, c);
	xs.count = 2;
	create_intersection(&xs.intersections, params.root_b, cylinder);
	create_intersection(&xs.intersections, params.root_a, cylinder);
	return (xs);
}

t_object	*cylinder(void)
{
	t_object	*_cylinder;

	_cylinder = ft_calloc(1, sizeof(*_cylinder));
	_cylinder->material = material();
	mx_identity(&_cylinder->transform);
	_cylinder->intersect = intersect_cylinder;
	// _cylinder->normal = cube_normal_at;
	return (_cylinder);
}