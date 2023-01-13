/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 22:43:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/09 23:13:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_c3d	tcolor(double red, double green, double blue)
{
	return ((t_c3d) tuple_3d(red, green, blue, 0.0));
}

t_c3d	haddamard(t_c3d c1, t_c3d c2)
{
	t_c3d	result;

	result.x = c1.x * c2.x;
	result.y = c1.y * c2.y;
	result.z = c1.z * c2.z;
	return (result);
}