/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shearing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 12:40:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:46:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	shearing(t_shearing shear, t_matrix *result)
{
	mx_identity(result);
	(*result)[0][1] = shear.xy;
	(*result)[0][2] = shear.xz;
	(*result)[1][0] = shear.yx;
	(*result)[1][2] = shear.yz;
	(*result)[2][0] = shear.zx;
	(*result)[2][1] = shear.zy;
}
