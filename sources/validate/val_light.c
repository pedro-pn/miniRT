/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_light.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 13:17:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/14 14:53:10 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	light_count(t_bool increment)
{
	static int	count = 0;

	if (increment)
		count++;
	return (count);
}

static t_bool	check_light_status(char *line)
{
	if (*line != 'L')
		return (false);
	light_count(true);
	if (light_count(false) > 1)
		return (false);
	return (true);
}

t_bool	validate_light(char *line)
{
	if (check_light_status(line) == false)
		return (false);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_amb_light(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}
