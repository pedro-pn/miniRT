/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 21:32:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 00:27:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	obj_group_id(t_bool increment)
{
	static int	id;

	if (increment == true)
		id++;
	return (id);
}

t_bool	parse_group(char *line)
{
	++line;
	if (ft_strchr(" \t\n\0", *line) == 0)
		return (false);
	obj_group_id(true);
	return (true);
}
