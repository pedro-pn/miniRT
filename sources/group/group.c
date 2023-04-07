/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 21:09:25 by pedro             #+#    #+#             */
/*   Updated: 2023/04/06 22:55:41 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_group	*group(void)
{
	t_group	*g;

	g = ft_calloc(1, sizeof(*g));
	g->type = GROUP;
	g->intersect = intersect_group;
	mx_identity(&g->transform);
	return (g);
}

void	add_child(t_group *group, t_object *object)
{
	ft_lstadd_back(&group->group, ft_lstnew(object));
	object->parent = group;
}

static void	free_group_tree(t_group *group)
{
	t_group	*g;
	t_list	*g_node;
	
	g_node = group->group;
	while (g_node)
	{
		g = g_node->content;
		if (g->type == GROUP)
			free_group_tree(g);
		g_node = g_node->next;
	}
	ft_lstclear(&group->group, free);
}

void	free_group(t_group *group)
{
	free_group_tree(group);
	free(group);
	group = NULL;
}
