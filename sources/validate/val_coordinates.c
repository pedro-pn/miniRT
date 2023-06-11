/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:58:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/11 12:28:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static int	val_norm_coordinate(char *line);

int	check_norm_coordinate(char *line)
{
	if (check_coordinate(line) == false)
		return (false);
	if (val_norm_coordinate(line) == false)
		return (false);
	return (true);
}

static int	val_norm_coordinate(char *line)
{
	char		**cord;
	double		x;
	double		y;
	double		z;

	cord = ft_split(line, ',');
	x = ft_atof(cord[0]);
	y = ft_atof(cord[1]);
	z = ft_atof(cord[2]);
	ft_clean_array((void **)cord, free);
	if (x < -1 || x > 1)
		return (false);
	if (y < -1 || y > 1)
		return (false);
	if (z < -1 || z > 1)
		return (false);
	return (true);
}

int	check_coordinate(char *line)
{
	if (!*line)
		return (false);
	if (ft_isfloat(&line) == false)
		return (false);
	line++;
	if (ft_isfloat(&line) == false)
		return (false);
	line++;
	if (ft_isfloat(&line) == false)
		return (false);
	if (*line != ' ' && *line != '\t')
		return (false);
	return (true);
}
