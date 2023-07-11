/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:10:21 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 10:32:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_bool	line_starts_with(char const *line, char const *preffix)
{
	size_t	preffix_size;

	if (preffix == NULL || line == NULL)
		return (false);
	preffix_size = ft_strlen(preffix);
	if (ft_strncmp(line, preffix, preffix_size) == 0)
		return (true);
	return (false);
}

static void	parse_line(char **pline)
{
	char	*line;

	line = *pline;
	line = jump_spaces(line);
	if (*line == '\0')
		return ;
	if (*line == '#')
		return ;
	if (line_starts_with(line, "A"))
		return (parse_ambient_light(line));
	if (line_starts_with(line, "C"))
		return (parse_camera(line));
	if (line_starts_with(line, "L"))
		return (parse_light(line));
	if (line_starts_with(line, "sp"))
		return (parse_sphere(line));
	if (line_starts_with(line, "pl"))
		return (parse_plane(line));
	if (line_starts_with(line, "cy"))
		return (parse_cylinder(line));
	if (line_starts_with(line, "cb"))
		return (parse_cube(line));
	free(*pline);
	*pline = NULL;
}

static void	parser_error(int fd)
{
	ft_clean_gnl(fd);
	safe_close(fd);
	die(UNIMPLEMENTED_PARSER_ERR);
}

void	parse_scene(void)
{
	int		fd;
	char	*line;

	fd = safe_open(scene());
	line = get_next_line(fd);
	if (line == NULL)
		die(GNL_ERROR);
	while (line)
	{
		parse_line(&line);
		if (line == NULL)
			parser_error(fd);
		free(line);
		line = get_next_line(fd);
	}
	safe_close(fd);
}
