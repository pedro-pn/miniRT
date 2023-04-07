/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 22:45:08 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 23:06:47 by pedro            ###   ########.fr       */
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
	node_objs = object->group;
	result.intersections = NULL;
	result.count = 0;
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
