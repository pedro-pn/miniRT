/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:53:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 22:20:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_normal(t_parser *parser, t_v3d normal)
{
	parser->normals = ft_realloc(parser->normals,
		sizeof(normal) * parser->n_count, sizeof(normal)
			* (parser->n_count + 1));
	parser->normals[parser->n_count] = normal;
	parser->n_count++;
}

// note: this function will be removed when parse_coordinate is implemented
t_bool	parse_normals(t_parser *parser, char *line)
{
	char	**coordinates;
	t_v3d	normal;

	++line;
	++line;
	line = jump_spaces(line);
	if (check_coordinate(line) == false)
		return (false);
	coordinates = ft_split(line, ' ');
	normal.x = ft_atof(coordinates[0]);
	normal.y = ft_atof(coordinates[1]);
	normal.z = ft_atof(coordinates[2]);
	normal.w = 0;
	add_normal(parser, normal);
	ft_clean_array((void **) coordinates, free);
	return (true);
}
