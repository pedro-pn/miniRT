/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_cube.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:57:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 10:09:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	validate_cube(char *line)
{
	if (ft_strncmp(line, "cb ", 3) && ft_strncmp(line, "cb\t", 3))
		return (false);
	line = get_next_info(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (isfloat(&line) == false)
		return (false);
	line = get_next_info(line);
	if (isfloat(&line) == false)
		return (false);
	line = get_next_info(line);
	if (isfloat(&line) == false)
		return (false);
	line = get_next_info(line);
	if (is_rgb(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}
