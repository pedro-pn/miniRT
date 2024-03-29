/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 10:07:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:10:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	translation(t_v3d direction, t_matrix *transform)
{
	mx_identity(transform);
	(*transform)[0][3] = direction.x;
	(*transform)[1][3] = direction.y;
	(*transform)[2][3] = direction.z;
}
