/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bvh_test.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 14:28:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 14:19:14 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*sphere_1(t_v3d trans, t_c3d color)
{
	t_object	*middle;

	middle = sphere();
	translation(trans, &middle->transform);
	middle->material.color = tcolor(color.x, color.y, color.z);
	middle->material.diffuse = 0.2;
	middle->material.specular = 0.3;
	middle->material.transparency = 0;
	middle->material.ambient = 0.4;
	middle->material.refractive_index = 2.0;
	return (middle);
}

static t_group	*create_group(void)
{
	double 	i;
	double 	j;
	double 	k;
	double	red;
	double	green;
	double	blue;
	t_group	*g;

	g = group();
	i = -15;
	while (i < 15)
	{
		j = -15;
		while (j < 15)
		{
			k = -15;
			while (k < 15)
			{
				blue = 1.0 * (k + 15) / 30;
				green = 1.0 * (j + 15) / 30;
				red = 1.0 * (i + 15) / 30;
				add_child(g, sphere_1(vector(i, j, k), tcolor(red, green, blue)));
				k +=3;
			}
			j +=3;
		}
		i += 3;
	}
	return (g);
}

static void	create_spheres_group(void)
{
	t_group		*g;
	t_matrix	rot_x;
	t_matrix	rot_y;
	t_matrix	scal;
	t_matrix	mx;


	g = create_group();
	rotation_x(-MY_PI / 9.2, &rot_x);
	rotation_y(-MY_PI / 6, &rot_y);
	scaling(vector(0.5, 0.5, 0.5), &scal);
	mx_product(rot_x, rot_y, &mx);
	mx_product(mx, scal, &g->transform);
	create_object(g);
}

static void create_world_objects(void)
{
	create_spheres_group();
	set_light(point(0, -1, -25), 1.0);
	set_ambient_light(1.0, white_rgb());
}

static void	create_world_camera(void)
{
	t_view	view;

	set_camera(250, 250, MY_PI / 3);
	view.from = point(0, -1.5, -30);
	view.to = point(0, -1.5, 0);
	view.up = vector(0, 1, 0);
	view_transformation(view, &camera()->transform);
}

void	bvh_test(void)
{
	create_world_objects();
	create_world_camera();
	divide(world()->objects->content, 1);
	render();
	mlx_save_img_to_ppm(image(), "bvh_test.ppm");
}
