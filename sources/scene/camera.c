/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:21:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:31:26 by ppaulo-d         ###   ########.fr       */
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

static t_v3d	resolve_up_vector(t_v3d orientation)
{
	t_v3d	temp;

	if (comp(orientation.y, 1.0)
		|| comp(orientation.y, -1.0))
	{
		temp = cross(orientation, vector(1, 0, 0));
		return (cross(temp, orientation));
	}
	return (vector(0, 1, 0));
}

void	set_scene_camera(t_p3d origin, t_v3d orientation, double horz_fov_deg)
{
	t_camera	*cam;
	t_view		view;

	cam = &(data()->camera);
	cam->origin = origin;
	cam->orientation = orientation;
	cam->fov_deg = horz_fov_deg;
	cam->fov_rad = degrees_to_radians(horz_fov_deg);
	set_camera(SCREEN_WIDTH, SCREEN_HEIGHT, cam->fov_rad);
	view.from = origin;
	view.to = add(origin, orientation);
	view.up = resolve_up_vector(orientation);
	view_transformation(view, &cam->transform);
}
