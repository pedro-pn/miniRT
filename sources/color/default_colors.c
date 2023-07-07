/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_colors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 09:29:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 14:00:25 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_c3d	black(void)
{
	return ((t_c3d){0, 0, 0, COLOR});
}

t_c3d	white(void)
{
	return ((t_c3d){1, 1, 1, COLOR});
}

t_rgb	white_rgb(void)
{
	return ((t_rgb){255, 255, 255});
}
