/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   patterns.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:52:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/30 10:42:14 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	stripe_pattern(t_c3d color_a, t_c3d color_b)
{
	return ((t_patt){color_a, color_b, true});
}

t_c3d	stripe_at(t_patt patt, t_p3d point)
{
	if ((int)floor(point.x) % 2 == 0)
		return (patt.a);
	return (patt.b);
}
