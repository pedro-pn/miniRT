/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/19 19:57:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_faces(void *face)
{
	t_face	*_face;

	_face = face;
	if (face == NULL)
		return ;
	free(_face->faces);
	free(_face);
	_face = NULL;
}

static t_bool	clean_parse_faces(t_parser *parser, t_face *face)
{
	ft_lstclear(&parser->faces, clean_faces);
	free(face);
	return (false);
}

static	void	add_faces(t_face *face, int vertex)
{
	face->faces = ft_realloc(face->faces, sizeof(vertex) * face->size,
			(face->size + 1) * sizeof(vertex));
	face->faces[face->size] = vertex;
	face->size++;
}

static t_bool	make_faces(t_parser *parser, char *line)
{
	t_face		*face;
	int			vertex;

	face = ft_calloc(1, sizeof(*face));
	while (*line != '\0')
	{
		vertex = ft_atoi(line);
		if (vertex == 0 || vertex > (int) parser->count)
			return (clean_parse_faces(parser, face));
		add_faces(face, vertex);
		line = jump_spaces(++line);
	}
	if (face->size < 3)
		return (clean_parse_faces(parser, face));
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
