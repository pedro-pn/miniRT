/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:06 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/13 11:40:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	scaling(t_v3d direction, t_matrix *transform)
{
	mx_identity(transform);
	(*transform)[0][0] = direction.x;
	(*transform)[1][1] = direction.y;
	(*transform)[2][2] = direction.z;
}
