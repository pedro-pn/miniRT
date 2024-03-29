/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:45:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 10:47:56 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_init(void)
{
	t_mlx_img	*_img;

	_img = image();
	_img->img = mlx_new_image(data()->mlx, camera()->hsize, camera()->vsize);
	_img->_width = camera()->hsize;
	_img->_height = camera()->vsize;
	_img->addr = mlx_get_data_addr(_img->img, &_img->bits_per_pixel,
			&_img->line_length, &_img->endian);
}

void	start_mlx(void)
{
	t_data	*_data;

	_data = data();
	_data->mlx = mlx_init();
	// _data->mlx_win = mlx_new_window(_data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
	// 		"minirt");
}
