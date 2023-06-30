/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 09:53:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/30 16:24:48 by ppaulo-d         ###   ########.fr       */
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

static t_bool	parser_obj_line(t_parser *parser, char *line)
{
	line = jump_spaces(line);
	if (ft_strncmp(line, "vn", 2) == 0)
		return (parse_normals(parser, line));
	else if (ft_strncmp(line, "vt", 2) == 0)
		return (true);
	else if (ft_strncmp(line, "v", 1) == 0)
		return (parse_vertices(parser, line));
	else if (ft_strncmp(line, "f", 1) == 0)
		return (parse_faces(parser, line));
	else if (ft_strncmp(line, "g", 1) == 0)
		return (parse_group(line));
	return (true);
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
