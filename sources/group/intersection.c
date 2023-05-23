/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:45:08 by pedro             #+#    #+#             */
/*   Updated: 2023/05/08 15:10:28 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intxs	intersect_group(t_object *object, t_ray ray)
{
	t_list		*node_objs;
	t_object	*obj;
	t_intxs		result;
	t_intxs		xs;

	ray = ray_transf_inverse(object->transform, ray);
	result = empty_intersection();
	if (intersect_bounding_box(object->bound_of(*object), ray) == false)
		return (result);
	node_objs = object->group;
	while (node_objs != NULL)
	{
		obj = node_objs->content;
		xs = obj->intersect(obj, ray);
		result.count += xs.count;
		ft_lstadd_back(&result.intersections, xs.intersections);
		node_objs = node_objs->next;
	}
	if (result.intersections != NULL)
		sort_intersections(result.intersections);
	return (result);
}
