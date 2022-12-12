/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 15:41:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	camera_count(char id)
{
	static int count = 0;
	
	if (id != 'C')
		return (FALSE);
	count++;
	if (count > 1)
		return (FALSE);
	return (TRUE);
}

int	validate_camera(char *line)
{
	if (camera_count(*line) == FALSE)
		return (FALSE);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	if (check_norm_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (validate_fov(line) == FALSE)
		return (FALSE);
	line = jump_info(line);
	if ((!ft_strchr(" \n", *line)))
		return (FALSE);
	return (TRUE);
}

int	check_norm_coordinate(char *line)
{
	char		**cord;
	double		x;
	double		y;
	double		z;

	cord = ft_split(line, ',');
	x = ft_atof(cord[0]);
	y = ft_atof(cord[1]);
	z = ft_atof(cord[2]);
	free_array((void **)cord);
	if (x < -1 || x > 1)
		return (FALSE);
	if (y < -1 || y > 1)
		return (FALSE);
	if (z < -1 || z > 1)
		return (FALSE);
	return (TRUE);
}

int	validate_fov(char *line)
{
	char	*line_hold;
	int		fov;

	line_hold = line;
	if (!ft_isdigit(*line))
		return (FALSE);
	while (ft_isdigit(*line))
		line++;
	if ((!ft_strchr(" \t\n", *line)) && !*line)
		return (FALSE);
	fov = ft_atoi(line_hold);
	if (fov < 0 || fov > 255)
		return (FALSE);
	return (TRUE);
}