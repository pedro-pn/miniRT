/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:09:25 by pedro             #+#    #+#             */
/*   Updated: 2023/04/10 23:52:07 by pedro            ###   ########.fr       */
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
	mx_identity(&g->transform);
	return (g);
}

void	add_child(t_group *group, t_object *object)
{
	ft_lstadd_back(&group->group, ft_lstnew(object));
	object->parent = group;
}

t_p3d	world_to_object(t_object *shape, t_p3d point)
{
	t_matrix	inverse;

	if (shape->parent)
		point = world_to_object(shape->parent, point);
	mx_inverse(shape->transform, &inverse);
	return (mx_tuple_product(inverse, point));
}
