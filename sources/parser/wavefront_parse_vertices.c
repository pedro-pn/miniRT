/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront_parse_vertices.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 15:39:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 15:44:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_vertex(t_parser *parser, t_p3d vertex)
{
	parser->vertices = ft_realloc(parser->vertices,
		sizeof(vertex) * parser->vtx_count, sizeof(vertex)
			* (parser->vtx_count + 1));
	parser->vertices[parser->vtx_count] = vertex;
	parser->vtx_count++;
}

// note: this function will be removed when parse_coordinate is implemented
t_bool	parse_vertices(t_parser *parser, char *line)
{
	char	**coordinates;
	t_p3d	vertex;

	++line;
	line = jump_spaces(line);
	if (check_coordinate(line) == false)
		return (false);
	coordinates = ft_split(line, ' ');
	vertex.x = ft_atof(coordinates[0]);
	vertex.y = ft_atof(coordinates[1]);
	vertex.z = ft_atof(coordinates[2]);
	vertex.w = 1;
	add_vertex(parser, vertex);
	ft_clean_array((void **) coordinates, free);
	return (true);
}
