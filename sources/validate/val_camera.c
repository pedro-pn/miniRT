/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_camera.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 18:11:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 09:59:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	camera_count(char id)
{
	static int	count = 0;

	if (id != 'C')
		return (false);
	count++;
	if (count > 1)
		return (false);
	return (true);
}

t_bool	validate_camera(char *line)
{
	if (camera_count(*line) == false)
		return (false);
	line++;
	line = jump_spaces(line);
	if (check_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (check_norm_coordinate(line) == false)
		return (false);
	line = get_next_info(line);
	if (validate_fov(line) == false)
		return (false);
	line = jump_info(line);
	if ((!ft_strchr(" \n", *line)))
		return (false);
	return (true);
}

t_bool	validate_fov(char *line)
{
	char	*line_hold;
	int		fov;

	line_hold = line;
	if (!ft_isdigit(*line))
		return (false);
	while (ft_isdigit(*line))
		line++;
	if ((!ft_strchr(" \t\n", *line)) && !*line)
		return (false);
	fov = ft_atoi(line_hold);
	if (fov < 0 || fov > 255)
		return (false);
	return (true);
}
