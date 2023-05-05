/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:17:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/05 17:46:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	box_contains_box(t_box b1, t_box b2)
{
	if (box_contains_point(b1, b2.max) && box_contains_point(b1, b2.min))
		return (true);
	return (false);
}

t_bbox	bounding_box_corners(t_box box)
{
	t_bbox	bbox;

	bbox.p1 = box.min;
	bbox.p2 = point(box.min.x, box.min.y, box.max.z);
	bbox.p3 = point(box.min.x, box.max.y, box.min.z);
	bbox.p4 = point(box.min.x, box.max.y, box.max.z);
	bbox.p5 = point(box.max.x, box.min.y, box.min.z);
	bbox.p6 = point(box.max.x, box.min.y, box.max.z);
	bbox.p7 = point(box.max.x, box.max.y, box.min.z);
	bbox.p8 = box.max;
	return (bbox);
}

t_box	transform_bbox(t_box box, t_matrix mx)
{
	t_bbox	bbox;
	t_box	result;

	bbox = bounding_box_corners(box);
	result = empty_bounding_box();
	add_point(&result, mx_tuple_product(mx, bbox.p1));
	add_point(&result, mx_tuple_product(mx, bbox.p2));
	add_point(&result, mx_tuple_product(mx, bbox.p3));
	add_point(&result, mx_tuple_product(mx, bbox.p4));
	add_point(&result, mx_tuple_product(mx, bbox.p5));
	add_point(&result, mx_tuple_product(mx, bbox.p6));
	add_point(&result, mx_tuple_product(mx, bbox.p7));
	add_point(&result, mx_tuple_product(mx, bbox.p8));
	return (result);
}

t_box	parent_space_bounds_of(t_object obj)
{
	return (transform_bbox(obj.bound_of(obj), obj.transform));
}

t_bool	intersect_bounding_box(t_box box, t_ray ray)
{
	t_p3d	min;
	t_p3d	max;
	double	t[2];
	double	limits[2];

	// ray = ray_transf_inverse(cube->transform, ray);
	limits[0] = box.min.x;
	limits[1] = box.max.x;
	check_axis(ray.origin.x, ray.direction.x, t, limits);
	min.x = t[0];
	max.x = t[1];
	limits[0] = box.min.y;
	limits[1] = box.max.y;
	check_axis(ray.origin.y, ray.direction.y, t, limits);
	min.y = t[0];
	max.y = t[1];
	limits[0] = box.min.z;
	limits[1] = box.max.z;
	check_axis(ray.origin.z, ray.direction.z, t, limits);
	min.z = t[0];
	max.z = t[1];
	get_cube_t(min, max, t);
	if (t[0] > t[1])
		return (false);
	return (true);
}
