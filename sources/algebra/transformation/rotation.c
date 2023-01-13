/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:40:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/13 12:22:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	rotation_x(double ang, t_matrix *result)
{
	mx_identity(result);
	(*result)[1][1] = cos(ang);
	(*result)[1][2] = -sin(ang);
	(*result)[2][1] = sin(ang);
	(*result)[2][2] = cos(ang);
}

void	rotation_y(double ang, t_matrix *result)
{
	mx_identity(result);
	(*result)[0][0] = cos(ang);
	(*result)[0][2] = sin(ang);
	(*result)[2][0] = -sin(ang);
	(*result)[2][2] = cos(ang);
}

void	rotation_z(double ang, t_matrix *result)
{
	mx_identity(result);
	(*result)[0][0] = cos(ang);
	(*result)[0][1] = -sin(ang);
	(*result)[1][0] = sin(ang);
	(*result)[1][1] = cos(ang);
}
