/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 17:54:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

int	get_rgb_color(t_rgb rgb)
{
	return (get_color(rgb.r, rgb.g, rgb.b));
}

t_rgb	color_rgb(int red, int green,  int blue)
{
	return ((t_rgb){red, green, blue});
}
