/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/11 12:24:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	validate_plane(char *line)
{
	if (ft_strncmp(line, "pl ", 3) && ft_strncmp(line, "pl\t", 3))
		return (false);
	line = get_next_info(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}
