/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val_cone.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 11:24:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/08/01 19:38:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	validate_cone(char *line)
{
	t_bool	status;
	if (ft_strncmp(line, "cn ", 3) && ft_strncmp(line, "cn\t", 3))
		return (false);
	line[1] = 'y';
	status = validate_cylinder(line);
	line[1] = 'n';
	return (status);
}
