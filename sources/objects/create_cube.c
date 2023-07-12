/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_cube.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:48:39 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/12 12:57:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_cube(t_object *cube, t_create_cube p)
{
	cube->material.color = rgb_to_tcolor(p.color);
	translate_object(cube, p.origin);
	fast_rotate_object(cube, p.normal);
	scale_object(cube, vector(p.width / 2.0, p.height / 2.0, p.length / 2.0));
}

void	create_cube(t_create_cube params)
{
	t_object	*_cube;

	_cube = cube();
	set_cube(_cube, params);
	create_object(_cube);
	add_child(rt_objects(), _cube);
}
