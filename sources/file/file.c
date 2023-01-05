/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 13:31:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

// void	file_init(t_file *file)
// {
// 	file->ambient = NULL;
// 	file->camera = NULL;
// 	file->cylinder = NULL;
// 	file->light = NULL;
// 	file->plane = NULL;
// 	file->sphere = NULL;
// }

void	validate_scene(char *filename)
{
	int		fd;
	char	*line;

	fd = open(filename, O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		if (validate_line(line) == FALSE)
			error_validate(line, fd);
		free(line);
		line = get_next_line(fd);
	}
}

int	validate_line(char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (TRUE);
	else if (*line == '\n' || !*line)
		return (TRUE);
	if (validate_camera(line) == TRUE)
		return (TRUE);
	if (validate_light(line))
		return (TRUE);
	if (validate_ambient(line))
		return (TRUE);
	if (validate_sphere(line))
		return (TRUE);
	if (validate_plane(line))
		return (TRUE);
	if (validate_cylinder(line))
		return (TRUE);
	return (FALSE);
}

void	error_validate(char *line, int fd)
{
	free(line);
	close(fd);
	ft_putendl_fd("Error\nminirt: Invalid scene file.", 2);
	exit(1);
}
