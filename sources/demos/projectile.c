/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projectile.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 20:23:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 12:11:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

t_projectile	tick(t_environment env, t_projectile proj)
{
	proj.position = add(proj.position, proj.velocity);
	proj.velocity = add(add(proj.velocity, env.gravity), env.wind);
	return (proj);
}

void	projectile_demo(void)
{
	t_projectile	proj;
	t_environment	env;

	set_camera(200, 200, MY_PI / 2);
	proj.position = point(0, 1, 0);
	proj.velocity = normalize(vector(1, 1, 0));
	proj.velocity = scalar_times(2.0, proj.velocity);
	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);
	while (proj.position.y > 0)
	{
		proj = tick(env, proj);
		mlx_draw_pixel_rgb(image(), (int) proj.position.x, (int)(image()->_height - proj.position.y),
			(t_rgb){255, 255, 255});
	}
//	mlx_put_image_to_window(data()->mlx, data()->mlx_win, image()->img, 0, 0);
//	mlx_loop(data()->mlx);
	mlx_save_img_to_ppm(image(), "projectile.ppm");
}