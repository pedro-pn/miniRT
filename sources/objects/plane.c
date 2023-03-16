/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:50:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/16 18:25:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	plane_normal_at(t_object plane, t_p3d point)
{
	(void)plane;
	(void)point;
	return (vector(0.0, 1.0, 0.0));
}

t_intxs	intersect_plane(t_object *plane, t_ray ray)
{
	t_intxs	xs;
	double	t;

	ray = ray_transf_inverse(plane->transform, ray);
	xs = empty_intersection();
	if (comp(ray.direction.y, 0))
		return (xs);
	t = -ray.origin.y / ray.direction.y;
	create_intersection(&xs, t, plane);
	return (xs);
}

t_object	*plane(void)
{
	t_object	*_plane;

	_plane = ft_calloc(1, sizeof(*_plane));
	_plane->type = PLANE;
	_plane->material = material();
	_plane->intersect = intersect_plane;
	_plane->normal = plane_normal_at;
	mx_identity(&_plane->transform);
	return (_plane);
}
