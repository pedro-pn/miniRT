/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:52:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 10:06:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

char	*jump_spaces(char *line)
{
	while (*line && ft_strchr(SPACES, *line))
		line++;
	return (line);
}

t_bool	isfloat(char **nptr)
{
	if (ft_strchr("-+", **nptr))
		(*nptr)++;
	if (!ft_isdigit(**nptr))
		return (false);
	while (ft_isdigit(**nptr))
		(*nptr)++;
	if (**nptr == '.')
		(*nptr)++;
	else if (ft_strchr(", \t\n\r", **nptr) || !**nptr)
		return (true);
	if (!ft_isdigit(**nptr))
		return (false);
	while (ft_isdigit(**nptr))
		(*nptr)++;
	if (ft_strchr(", \t\n\r", **nptr) || !**nptr)
		return (true);
	return (false);
}

char	*jump_info(char *line)
{
	while (*line && !ft_strchr(" \t\n", *line))
		line++;
	return (line);
}

char	*get_next_info(char *line)
{
	char	*info;

	info = jump_info(line);
	if (*info)
		info = jump_spaces(info);
	return (info);
}
