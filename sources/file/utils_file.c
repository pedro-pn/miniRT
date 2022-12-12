/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:52:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 19:58:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

char	*jump_spaces(char *line)
{
	while (*line && ft_strchr(SPACES, *line))
		line++;
	return (line);
}

int	ft_isfloat(char **nptr)
{
	if (ft_strchr("-+", **nptr))
		(*nptr)++;
	if (!ft_isdigit(**nptr))
		return (FALSE);
	while (ft_isdigit(**nptr))
		(*nptr)++;
	if (**nptr == '.')
		(*nptr)++;
	else if (ft_strchr(", \t\n", **nptr) || !**nptr)
		return (TRUE);
	if (!ft_isdigit(**nptr))
		return (FALSE);
	while (ft_isdigit(**nptr))
		(*nptr)++;
	if (ft_strchr(", \t\n", **nptr) || !**nptr)
		return (TRUE);
	return (FALSE);
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
