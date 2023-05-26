/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_partition_bhv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:37:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/26 11:38:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bucks	partition_children(t_group *g)
{
	t_bucks		bucket;
	t_sbox		sbox;
	t_object	*obj;
	t_list		*node;

	sbox = split_bounds(g->bound_of(*g));
	node = g->group;
	bucket = (t_bucks){NULL, NULL};
	while (node)
	{
		obj = node->content;
		if (box_contains_box(sbox.left, parent_space_bounds_of(*obj)))
		{
			ft_lstadd_back(&bucket.left, ft_lstnew(obj));
			node = node->next;
			ft_lstremove(&g->group, obj);
			continue ;
		}
		else if (box_contains_box(sbox.right, parent_space_bounds_of(*obj)))
		{
			ft_lstadd_back(&bucket.right, ft_lstnew(obj));
			node = node->next;
			ft_lstremove(&g->group, obj);
			continue ;
		}
		node = node->next;
	}
	return (bucket);
}