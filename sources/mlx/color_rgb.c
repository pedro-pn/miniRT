/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/07 14:02:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"

int	get_rgb_color(t_rgb rgb)
{
	return (get_color(rgb.r, rgb.g, rgb.b));
}

t_rgb	color_rgb(int _red, int _green,  int _blue)
{
	return ((t_rgb){_red, _green, _blue});
}
