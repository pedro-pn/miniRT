/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:53:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/16 11:25:45 by ppaulo-d         ###   ########.fr       */
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
	t_p3d	*new_vertexes;

	if (parser->vertexes == NULL)
	{
		parser->vertexes = malloc(sizeof(vertex));
		parser->vertexes[0] = vertex;
		parser->count = 1;
		return ;
	}
	new_vertexes = malloc(sizeof(*parser->vertexes) * (parser->count + 1));
	ft_memcpy(new_vertexes, parser->vertexes, parser->count * sizeof(vertex));
	parser->count++;
	new_vertexes[parser->count - 1] = vertex;
	free(parser->vertexes);
	parser->vertexes = new_vertexes;
}

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
	vertex.w = 0;
	add_vertex(parser, vertex);
	ft_clean_array((void **) coordinates, free);
	return (true);
}

static t_bool	parser_obj_line(t_parser *parser, char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (true);
	if (*line == 'v')
		return (parse_vertex(parser, line));
	return (false);
}

t_parser	parser_obj_file(int file)
{
	t_parser	parser;
	char		*line;

	parser.vertexes = NULL;
	parser.count = 0;
	line = get_next_line(file);
	while (line)
	{
		if (parser_obj_line(&parser, line) == false) {
			ft_putstr_fd("failed to parser at line: ", 2);
			ft_putnbr_fd(line_count(false), 2);
			ft_putendl_fd("", 2);
			free(parser.vertexes);
			free(line);
			break ;
		}
		free(line);
		line = get_next_line(file);
		line_count(true);
	}
	return (parser);
}
