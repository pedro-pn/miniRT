/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/22 21:39:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	default_world(void)
{
	t_object	*_sphere;

	_sphere = sphere();
	_sphere->material.color = tcolor(0.8, 1.0, 0.6);
	_sphere->material.diffuse = 0.7;
	_sphere->material.specular = 0.2;
	create_object(_sphere);
	_sphere = sphere();
	scaling(vector(0.5, 0.5, 0.5), &_sphere->transform);
	create_object(_sphere);
}
