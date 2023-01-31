/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 11:02:08 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/31 11:06:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	checkers_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.patt_at = checkers_at;
	return (patt);
}

t_c3d	checkers_at(t_patt patt, t_p3d point)
{
	int	local;

	local = (int)(floor(point.x) + floor(point.y) + floor(point.z));
	if (local % 2 == 0)
		return (patt.a);
	return (patt.b);
}
