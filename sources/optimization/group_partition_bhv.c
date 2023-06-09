/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_partition_bhv.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 23:37:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/08 23:19:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_list	*split_children(t_group *g, t_object *obj, t_list **bucket,
								t_list *node)
{
	ft_lstadd_back(bucket, ft_lstnew(obj));
	node = node->next;
	ft_lstremove(&g->group, obj);
	return (node);
}

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
			node = split_children(g, obj, &bucket.left, node);
		else if (box_contains_box(sbox.right, parent_space_bounds_of(*obj)))
			node = split_children(g, obj, &bucket.right, node);
		else
			node = node->next;
	}
	return (bucket);
}

void	make_subgroup(t_group *g, t_list *objs)
{
	t_group	*subgroup;

	subgroup = group();
	subgroup->group = objs;
	ft_lstadd_back(&g->group, ft_lstnew(subgroup));
}

void	divide(t_group *g, int threashold)
{
	t_bucks		buckets;
	t_object	*child;
	t_list		*node;

	if (threashold <= ft_lstsize(g->group))
	{
		buckets = partition_children(g);
		if (buckets.left)
			make_subgroup(g, buckets.left);
		if (buckets.right)
			make_subgroup(g, buckets.right);
	}
	node = g->group;
	while (node)
	{
		child = node->content;
		divide(child, threashold);
		node = node->next;
	}
}
