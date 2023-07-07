/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_plane.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:17:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:32:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	set_plane(t_object *plane, t_p3d origin, t_p3d normal, t_rgb color)
{
	plane->material.color = rgb_to_tcolor(color);
	translate_object(plane, origin);
	fast_rotate_object(plane, normal);
}

void	create_plane(t_p3d origin, t_p3d normal, t_rgb color)
{
	t_object	*_plane;

	(void)normal;
	_plane = plane();
	set_plane(_plane, origin, normal, color);
	create_object(_plane);
}
