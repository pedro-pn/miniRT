/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_coordinates.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:58:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 10:05:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	val_norm_coordinate(char *line);

t_bool	check_norm_coordinate(char *line)
{
	if (check_coordinate(line) == false)
		return (false);
	if (val_norm_coordinate(line) == false)
		return (false);
	return (true);
}

static t_bool	val_norm_coordinate(char *line)
{
	char		**cord;
	double		x;
	double		y;
	double		z;
	t_v3d		normal;

	cord = ft_split(line, ',');
	x = ft_atof(cord[0]);
	y = ft_atof(cord[1]);
	z = ft_atof(cord[2]);
	normal = vector(x, y, z);
	ft_clean_array((void **)cord, free);
	if (comp(magnitude(normal), 1.0))
		return (true);
	return (false);
}

t_bool	check_coordinate(char *line)
{
	if (!*line)
		return (false);
	if (isfloat(&line) == false)
		return (false);
	line++;
	if (isfloat(&line) == false)
		return (false);
	line++;
	if (isfloat(&line) == false)
		return (false);
	if (ft_strchr(SPACES, *line) == NULL)
		return (false);
	return (true);
}
