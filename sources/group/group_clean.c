/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_clean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 23:51:36 by pedro             #+#    #+#             */
/*   Updated: 2023/04/11 21:15:06 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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

void	free_group(void *group)
{
	free_group_tree(group);
	free(group);
	group = NULL;
}
