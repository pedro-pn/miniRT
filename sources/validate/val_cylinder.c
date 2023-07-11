/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:03:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 11:36:45 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_cy_dimension(char **line);

t_bool	validate_cylinder(char *line)
{
	if (ft_strncmp(line, "cy ", 3) && ft_strncmp(line, "cy\t", 3))
		return (false);
	line = get_next_info(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_cy_dimension(&line) == false)
		return (false);
	line = get_next_info(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}

static t_bool	check_cy_dimension(char **line)
{
	if (isfloat(line) == false)
		return (false);
	*line = get_next_info(*line);
	if (isfloat(line) == false)
		return (false);
	return (true);
}
