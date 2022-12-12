/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_sphere.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:43:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 18:32:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

int	validate_sphere(char *line)
{
	if (!ft_strncmp(line, "sp ", 3) && !ft_strncmp(line, "sp\t", 3))
		return (FALSE);
	line = get_next_info(line);
	if (check_coordinate(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}
