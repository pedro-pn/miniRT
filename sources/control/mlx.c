/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:30:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 14:53:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	start_mlx(void)
{
	t_data	*_data;

	_data = data();
	_data->mlx = mlx_init();
	_data->mlx_win = mlx_new_window(_data->mlx, SCREEN_WIDTH, SCREEN_HEIGHT,
			"minirt");
}

t_mlx_img	*image(void)
{	
	return (&(data()->img));
}

void	*window(void)
{
	return (data()->mlx_win);
}
