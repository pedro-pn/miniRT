/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:55:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/14 14:53:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	ambient_count(t_bool increment)
{
	static int	count = 0;

	if (increment)
		count++;
	return (count);
}

static t_bool	check_amb_status(char *line)
{
	if (*line != 'A')
		return (false);
	ambient_count(true);
	if (ambient_count(false) > 1)
		return (false);
	return (true);
}

t_bool	validate_ambient(char *line)
{
	if (check_amb_status(line) == false)
		return (false);
	line++;
	line = jump_spaces(line);
	if (check_amb_light(line) == false)
		return (false);
	line = jump_info(line);
	line = jump_spaces(line);
	if (check_color(line) == false)
		return (false);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (false);
	return (true);
}

t_bool	check_amb_light(char *line)
{
	char	*hold_line;
	double	ambient_light;

	hold_line = line;
	if (isfloat(&line) == false)
		return (false);
	ambient_light = ft_atof(hold_line);
	if (ambient_light < 0 || ambient_light > 1)
		return (false);
	return (true);
}
