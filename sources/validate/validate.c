/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 16:13:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/14 14:48:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	int	line_count(t_bool increment)
{
	static int line = 1;

	if (increment)
		line++;
	return (line);
}

void	validate_scene()
{
	int		fd;
	char	*line;

	check_scene_ext();
	fd = open(scene(), O_RDONLY);
	line = get_next_line(fd);
	if (line == NULL)
		die(GNL_ERROR);
	while (line)
	{
		if (validate_line(line) == false)
			error_validate(line, fd);
		free(line);
		line = get_next_line(fd);
		line_count(true);
	}
	safe_close(fd);
	check_scene_validation();
}

t_bool	validate_line(char *line)
{
	line = jump_spaces(line);
	if (*line == '#')
		return (true);
	else if (*line == '\n' || !*line)
		return (true);
	if (validate_camera(line) == true)
		return (true);
	if (validate_light(line))
		return (true);
	if (validate_ambient(line))
		return (true);
	if (validate_sphere(line))
		return (true);
	if (validate_plane(line))
		return (true);
	if (validate_cylinder(line))
		return (true);
	if (validate_cube(line))
		return (true);
	if (validate_cone(line))
		return (true);
	if (check_scene_status() == false)
		return (false);
	return (false);
}

void	error_validate(char *line, int fd)
{
	ft_clean_gnl(fd);
	safe_close(fd);
	ft_putendl_fd("Error\n Invalid scene file.", 2);
	if (*val_error())
		ft_putendl_fd(*val_error(), 2);
	ft_putstr_fd("line ", 2);
	ft_putnbr_fd(line_count(false), 2);
	ft_putendl_fd(":", 2);
	ft_putstr_fd("\t", 2);
	ft_putendl_fd(line, 2);
	free(line);
	exit(1);
}
