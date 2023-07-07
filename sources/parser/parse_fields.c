/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fields.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:42:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:37:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_rgb	parse_color(char *line)
{
	char	**tokens;
	t_rgb	color;

	tokens = ft_split(line, ',');
	color.r = ft_atoi(tokens[0]);
	color.g = ft_atoi(tokens[1]);
	color.b = ft_atoi(tokens[2]);
	ft_clean_array((void **) tokens, free);
	return (color);
}

t_v3d	parse_vector(char *line)
{
	char	**tokens;
	t_v3d	vector;

	tokens = ft_split(line, ',');
	vector.x = ft_atof(tokens[0]);
	vector.y = ft_atof(tokens[1]);
	vector.z = ft_atof(tokens[2]);
	vector.w = VECTOR;
	ft_clean_array((void **) tokens, free);
	return (vector);
}

t_p3d	parse_point(char *line)
{
	t_p3d	origin;

	origin = parse_vector(line);
	origin.w = POINT;
	return (origin);
}

char	*skip_field(char *line)
{
	line = jump_info(line);
	line = jump_spaces(line);
	return (line);
}
