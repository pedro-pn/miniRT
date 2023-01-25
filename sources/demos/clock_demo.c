/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clock_demo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:06:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:41:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clock_demo(void)
{
	int			count;
	t_p3d		origin;
	t_mlx_img	*img;
	t_matrix	rotation;

	set_camera(200, 200, MY_PI / 2);
	img = image();
	count = 0;
	origin = point(0, 50, 0);
	rotation_z(MY_PI / 6, &rotation);
	while (count < 30)
	{
		mlx_draw_pixel_rgb(img,
			round(origin.x + img->_width / 2),
			round(origin.y + img->_height / 2), color_rgb(255, 255,255));
		origin = mx_tuple_product(rotation, origin);
		count++;
	}
	mlx_save_img_to_ppm(img, "clock3.ppm");
}
