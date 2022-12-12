/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 17:52:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/08 16:33:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "file.h"

char	*jump_spaces(char *line)
{
	while (ft_strchr(SPACES, *line))
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
	else if (ft_strchr(", \t", **nptr))
		return (TRUE);
	if (!ft_isdigit(**nptr))
		return (FALSE);
	while (ft_isdigit(**nptr))
		(*nptr)++;
	if (ft_strchr(", \t", **nptr))
		return (TRUE);
	return (FALSE);
}

char	*jump_coordinate(char *line)
{
	while (*line && !ft_strchr(" \t\n", *line))
		line++;
	return (line);
}
