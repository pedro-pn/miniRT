/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_color.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 18:27:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/11 12:25:38 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	check_color(char *line)
{
	char	**rgb;
	int		r;
	int		g;
	int		b;

	if (is_rgb(line) == false)
		return (false);
	rgb = ft_split(line, ',');
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	free_array((void **)rgb);
	if (r < 0 || r > 255)
		return (false);
	if (g < 0 || g > 255)
		return (false);
	if (b < 0 || b > 255)
		return (false);
	return (true);
}

int	is_rgb(char *line)
{
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (false);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (*line != ',')
		return (false);
	line++;
	while (ft_isdigit(*line))
		line++;
	if (!ft_strchr("\t \n", *line))
		return (false);
	return (true);
}
