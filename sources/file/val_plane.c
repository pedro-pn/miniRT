/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_plane.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 19:35:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 19:50:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	validate_plane(char *line)
{
	if (ft_strncmp(line, "pl ", 3) && ft_strncmp(line, "pl\t", 3))
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
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}

