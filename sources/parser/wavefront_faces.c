/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront_faces.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 22:36:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_for_normals(char **line)
{
	while (ft_isdigit(**line))
		(*line)++;
	if (**line != '/')
		return (false);
	return (true);
}

static	t_bool	parse_face_vertice(t_face *face, char *line, size_t vtx_count)
{
	int	vertex;

	vertex = ft_atoi(line);
	if (vertex == 0 || vertex > (int) vtx_count)
		return (clean_faces(face), false);
	if (ft_arradd_int(&face->vtx_indexes, vertex, face->vtx_indexes_size))
		return (clean_faces(face), false);
	face->vtx_indexes_size++;
	return (true);
}

static t_bool	make_faces(t_parser const *parser, t_face *face, char *line)
{
	while (*line != '\0')
	{
		if (parse_face_vertice(face, line, parser->vtx_count) == false)
			return (false);
		if (check_for_normals(&line))
		{
			if (parse_face_normal(face, &line, parser->n_count) == false)
				return (false);
		}
		line = jump_info(line);
		line = jump_spaces(line);
	}
	return (true);
}

t_bool	parse_faces(t_parser *parser, char *line)
{
	t_face		*face;

	line = jump_spaces(++line);
	if (*line == '\0')
		return (false);
	face = ft_calloc(1, sizeof(*face));
	face->id = obj_group_id(false);
	if (make_faces(parser, face, line) == false)
		return (false);
	if (face->vtx_indexes_size < 3)
		return (clean_faces(face), false);
	ft_lstadd_back(&parser->faces, ft_lstnew(face));
	return (true);
}
