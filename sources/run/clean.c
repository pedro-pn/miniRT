/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:19:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 21:25:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_mlx(t_data *_data)
{
//	mlx_destroy_window(_data->mlx, _data->mlx_win);
	mlx_destroy_image(_data->mlx, _data->img.img);
	mlx_destroy_display(_data->mlx);
	free(_data->mlx);
}

void	clean_program(void)
{
	t_data	*_data;

	_data = data();
	clean_mlx(_data);
}
