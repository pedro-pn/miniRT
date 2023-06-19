/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_group.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:43:29 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/19 13:39:47 by ppaulo-d         ###   ########.fr       */
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
