/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:03:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 20:18:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static int	check_cy_dimension(char **line);

int	validate_cylinder(char *line)
{
	if (ft_strncmp(line, "cy ", 3) && ft_strncmp(line, "cy\t", 3))
		return (FALSE);
	line = get_next_info(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	if (check_norm_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_cy_dimension(&line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}

static int	check_cy_dimension(char **line)
{
	if (ft_isfloat(line) == FALSE)
		return (FALSE);
	*line = get_next_info(*line);
	if (ft_isfloat(line) == FALSE)
		return (FALSE);
	return (TRUE);
}