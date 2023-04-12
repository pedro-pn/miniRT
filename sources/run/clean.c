/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:19:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/11 21:16:14 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_mlx(t_data *_data)
{
//	mlx_destroy_window(_data->mlx, _data->mlx_win);
	mlx_destroy_image(_data->mlx, image()->img);
	mlx_destroy_display(_data->mlx);
	free(_data->mlx);
}

static void	clean_objects(void *object)
{
	t_object	*obj;

	obj = object;
	obj->clean(object);
}


void	clean_world(void)
{
	t_world	*_world;

	_world = world();
	ft_lstclear(&_world->objects, clean_objects);
}

void	clean_program(void)
{
	t_data	*_data;

	_data = data();
	clean_mlx(_data);
	clean_world();
}
