/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:45:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 16:54:06 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	initialize_args(int argc, char *argv[])
{
	set_argc(argc);
	set_argv(argv);
	set_scene(argv[1]);
}

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
	data()->mlx = mlx_init();
	if (data()->mlx == NULL)
		die(MLX_ERROR);
	// _data->mlx_win = mlx_new_window(_data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
	// 		"minirt");
}
