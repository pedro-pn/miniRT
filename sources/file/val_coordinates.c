/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:58:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 14:34:49 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static int	val_norm_coordinate(char *line);

int	check_norm_coordinate(char *line)
{
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	if (val_norm_coordinate(line) == FALSE)
		return (FALSE);
	return (TRUE);
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
	free_array((void **)cord);
	if (x < -1 || x > 1)
		return (FALSE);
	if (y < -1 || y > 1)
		return (FALSE);
	if (z < -1 || z > 1)
		return (FALSE);
	return (TRUE);
}

int	check_coordinate(char *line)
{
	if (!*line)
		return (FALSE);
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	line++;
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	line++;
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	if (*line != ' ' && *line != '\t')
		return (FALSE);
	return (TRUE);
}
