/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 10:18:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/09 10:28:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intxs	intersect_cylinder(t_object *cylinder, t_ray ray)
{
	double	a;
	double	b;
	double	c;
	double	disc;
	
	(void)cylinder;
	a = pow(ray.direction.x, 2) + pow(ray.direction.z, 2);
	if (comp(a, 0.0))
		return (empty_intersection());
	b = 2 * ray.origin.x * ray.direction.x + 2 * ray.origin.z * ray.direction.z;
	c = pow(ray.origin.x, 2) + pow(ray.origin.z, 2);
	disc = discriminant(a, b, c);
	if (disc < 0)
		return (empty_intersection());
	return ((t_intxs){1, NULL});
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