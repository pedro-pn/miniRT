/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 12:48:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/19 13:36:30 by ppaulo-d         ###   ########.fr       */
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

t_bool	parse_faces(t_parser *parser, char *line)
{
	size_t		vertex;
	t_face		*face;

	++line;
	line = jump_spaces(line);
	if (*line == '\0')
		return (false);
	face = ft_calloc(1, sizeof(*face));
	while (*line != '\0')
	{
		vertex = ft_atoi(line);
		if (vertex == 0 || vertex > parser->count) {
			ft_lstclear(&parser->faces, clean_faces);
			free(face);
			return (false);
		}
		face->faces = ft_realloc(face->faces, sizeof(vertex) * face->size, (face->size + 1) * sizeof(vertex));
		face->faces[face->size] = vertex;
		face->size++;
		line++;
		line = jump_spaces(line);
	}
	if (face->size < 3)
	{
		ft_lstclear(&parser->faces, clean_faces);
		free(face);
		return (false);
	}
	ft_lstadd_back(&parser->faces, ft_lstnew(face));
	return (true);
}
