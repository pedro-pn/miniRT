/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:53:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 22:19:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	line_count(t_bool increment)
{
	static int	line_count = 1;

	if (increment)
		line_count++;
	return (line_count);
}

static void	add_vertex(t_parser *parser, t_p3d vertex)
{
	parser->vertices = ft_realloc(parser->vertices,
		sizeof(vertex) * parser->vtx_count, sizeof(vertex)
			* (parser->vtx_count + 1));
	parser->vertices[parser->vtx_count] = vertex;
	parser->vtx_count++;
}

// note: this function will be removed when parse_coordinate is implemented
static	t_bool	parse_vertex(t_parser *parser, char *line)
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

static t_bool	parser_obj_line(t_parser *parser, char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (true);
	if (ft_strncmp(line, "vn", 2) == 0)
		return (parse_normals(parser, line));
	else if (ft_strncmp(line, "v", 1) == 0)
		return (parse_vertex(parser, line));
	else if (ft_strncmp(line, "f", 1) == 0)
		return (parse_faces(parser, line));
	else if (ft_strncmp(line, "g", 1) == 0)
		return (parse_group(line));
	else if (*line == '\0')
		return (true);
	return (false);
}

t_parser	parser_obj_file(int file)
{
	t_parser	parser;
	char		*line;

	parser = (t_parser){0};
	line = get_next_line(file);
	while (line)
	{
		if (parser_obj_line(&parser, line) == false) {
			ft_putstr_fd("failed to parser at line: ", 2);
			ft_putnbr_fd(line_count(false), 2);
			ft_putendl_fd("", 2);
			clean_parser(&parser);
			free(line);
			ft_clean_gnl(file);
			break ;
		}
		free(line);
		line = get_next_line(file);
		line_count(true);
	}
	return (parser);
}
