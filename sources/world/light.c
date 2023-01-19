/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/19 12:34:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	point_light(t_p3d position, t_c3d color)
{
	t_light	*_light;

	_light = light();
	_light->position = position;
	_light->color = color;
}
