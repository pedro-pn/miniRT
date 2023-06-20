/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:43:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 00:59:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	fan_triangulation(t_group *g, t_p3d const *vertices,
							t_face const *face)
{
	size_t		index;
	t_object	*tri;

	index = 1;
	while (index < face->size - 1)
	{
		tri = triangle(vertices[face->faces[0] - 1],
			vertices[face->faces[index] - 1],
			vertices[face->faces[index + 1] - 1]);
		tri->id = face->id;
		add_child(g, tri);
		index++;
	}
}

t_group	*default_group(t_parser parser)
{
	t_group		*g;
	t_list		*node;
	t_face		*face;

	if (ft_lstsize(parser.faces) == 0)
		return (NULL);
	g = group();
	node = parser.faces;
	while (node)
	{
		face = node->content;
		fan_triangulation(g, parser.vertices, face);
		node = node->next;
	}
	return (g);
}

static	t_group	*separate_by_group_id(t_group *g, int id)
{
	t_group		*sub_group;
	t_list		*node;
	t_object	*obj;

	node = g->group;
	sub_group = group();
	while (node)
	{
		obj = node->content;
		if (obj->id == 0)
			;
		else if (obj->id == id)
		{
			node = node->next;
			add_child(sub_group, obj);
			ft_lstremove(&g->group, obj);
		}
		node = node->next;
	}
	return (sub_group);
}

t_group	*obj_to_group(t_parser parser)
{
	t_group		*g;
	t_group		*sub_group;
	int			id;

	g = default_group(parser);
	id = 1;
	while (id <= obj_group_id(false))
	{
		sub_group = separate_by_group_id(g, id);
		add_child(g, sub_group);
		id++;
	}
	return (g);
}
