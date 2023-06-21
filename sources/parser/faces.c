/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 15:28:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	add_faces_index(t_face *face, int vertex_index)
{
	face->f_indexes = ft_realloc(face->f_indexes, sizeof(vertex_index)
			* face->faces_size,
				(face->faces_size + 1) * sizeof(vertex_index));
	face->f_indexes[face->faces_size] = vertex_index;
	face->faces_size++;
}

static t_bool	parse_face_normals(char **line)
{
	while (ft_isdigit(**line))
		(*line)++;
	if (**line != '/')
		return (false);
	return (true);
}

static t_bool	make_faces(t_parser *parser, char *line)
{
	t_face		*face;
	int			vertex;

	face = ft_calloc(1, sizeof(*face));
	face->id = obj_group_id(false);
	while (*line != '\0')
	{
		vertex = ft_atoi(line);
		if (vertex == 0 || vertex > (int) parser->vtx_count)
			return (clean_faces(face), false);
		add_faces_index(face, vertex);
		if (parse_face_normals(&line))
		{
			if (make_face_normals(parser, face, &line) == false)
				return (false);
		}
		line = jump_info(line);
		line = jump_spaces(line);
	}
	if (face->faces_size < 3)
		return (clean_faces(face), false);
	ft_lstadd_back(&parser->faces, ft_lstnew(face));
	return (true);
}

t_bool	parse_faces(t_parser *parser, char *line)
{
	line = jump_spaces(++line);
	if (*line == '\0')
		return (false);
	if (make_faces(parser, line) == false)
		return (false);
	return (true);
}
