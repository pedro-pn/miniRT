/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 16:04:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/05 16:09:28 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	group_bounding_box(t_object obj)
{
	t_box		box;
	t_box		cbox;
	t_object	*child;
	t_list		*node;

	box = empty_bounding_box();
	node = obj.group;
	while (node)
	{
		child = node->content;
		cbox = parent_space_bounds_of(*child);
		add_bounding_box(&box, cbox);
		node = node->next;
	}
	return (box);
}
