/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:30:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 14:36:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*mlx(void)
{
	return (data()->mlx);
}

t_mlx_img	*image(void)
{	
	return (&(data()->camera.img));
}

void	*window(void)
{
	return (data()->mlx_win);
}
