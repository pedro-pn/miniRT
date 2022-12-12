/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_ambient.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:55:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 14:30:29 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

static int	ambient_count(char id);

static int	ambient_count(char id)
{
	static int	count = 0;

	if (id != 'A')
		return (FALSE);
	count++;
	if (count > 1)
		return (FALSE);
	return (TRUE);
}

int	validate_ambient(char *line)
{
	if (ambient_count(*line) == FALSE)
		return (FALSE);
	line++;
	line = jump_spaces(line);
	if (check_amb_light(line) == FALSE)
		return (FALSE);
	line = jump_info(line);
	line = jump_spaces(line);
	if (check_color(line) == FALSE)
		return (FALSE);
	line = get_next_info(line);
	if (*line && !ft_strchr("\n", *line))
		return (FALSE);
	return (TRUE);
}

int	check_amb_light(char *line)
{
	char	*hold_line;
	double	ambient_light;

	hold_line = line;
	if (ft_isfloat(&line) == FALSE)
		return (FALSE);
	ambient_light = ft_atof(hold_line);
	if (ambient_light < 0 || ambient_light > 1)
		return (FALSE);
	return (TRUE);
}

int	check_color(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (is_rgb(line) == FALSE)
		return (FALSE);
	rgb = ft_split(line, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array((void **)rgb);
	if (r < 0 || r > 255)
		return (FALSE);
	if (g < 0 || g > 255)
		return (FALSE);
	if (b < 0 || b > 255)
		return (FALSE);
	return (TRUE);
}

int	is_rgb(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (FALSE);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (FALSE);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (!ft_strchr("\t \n", *line))
		return (FALSE);
	return (TRUE);
}