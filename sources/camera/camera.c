/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:21:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 10:59:37 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_camera(int hsize, int vsize, double field_of_view)
{
	t_camera	*cam;
	double		aspect;
	double		half_view;

	cam = camera();
	cam->hsize = hsize;
	cam->vsize = vsize;
	cam->field_of_view = field_of_view;
	half_view = tan(cam->field_of_view / 2);
	aspect = (double) cam->hsize / (double) cam->vsize;
	if (aspect >= 1)
	{
		cam->half_width = half_view;
		cam->half_height = half_view / aspect;
	}
	else
	{
		cam->half_width = half_view * aspect;
		cam->half_height = half_view;
	}
	cam->pixel_size = cam->half_width * 2.0 / cam->hsize;
	mx_identity(&cam->transform);
	img_init();
}
