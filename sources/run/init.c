/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:45:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/06 19:10:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	img_init(void)
{
	t_mlx_img	*_img;

	_img = image();
	_img->img = mlx_new_image(data()->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	_img->_width = SCREEN_WIDTH;
	_img->_height = SCREEN_HEIGHT;
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
