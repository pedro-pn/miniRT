/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:09:25 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 21:13:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_group	*group(void)
{
	t_group	*g;

	g = ft_calloc(1, sizeof(*g));
	g->type = GROUP;
	g->parent = NULL;
	g->intersect = intersect_group;
	g->group = NULL;
	g->clean = free_group;
	mx_identity(&g->transform);
	return (g);
}

void	add_child(t_group *group, t_object *object)
{
	ft_lstadd_back(&group->group, ft_lstnew(object));
	object->parent = group;
}

t_p3d	world_to_object(t_object object, t_p3d point)
{
	t_matrix	inverse;

	if (object.parent)
		point = world_to_object(*object.parent, point);
	mx_inverse(object.transform, &inverse);
	return (mx_tuple_product(inverse, point));
}

t_v3d	normal_to_world(t_object object, t_v3d normal)
{
	t_matrix	transpose;
	t_matrix	inverse;

	mx_transpose(object.transform, &transpose);
	mx_inverse(transpose, &inverse);
	normal = mx_tuple_product(inverse, normal);
	normal.w = 0;
	normal = normalize(normal);
	if (object.parent)
		 normal = normal_to_world(*object.parent, normal);
	return (normal);
}
