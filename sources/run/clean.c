/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 18:19:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 14:34:08 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	clean_mlx(void)
{
	if (mlx() != NULL)
	{
	//	mlx_destroy_window(_data->mlx, _data->mlx_win);
		mlx_destroy_image(mlx(), image()->img);
		mlx_destroy_display(mlx());
		free(mlx());
	}
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
	clean_mlx();
	clean_world();
}
