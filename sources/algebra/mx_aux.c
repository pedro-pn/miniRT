/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/10 13:19:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_row	mx_get_row(t_matrix mx, int i)
{
	t_row	row;

	row.x = mx[i][0];
	row.y = mx[i][1];
	row.z = mx[i][2];
	row.w = mx[i][3];
	return (row);
}

t_column	mx_get_column(t_matrix mx, int j)
{
	t_column	column;

	column.x = mx[0][j];
	column.y = mx[1][j];
	column.z = mx[2][j];
	column.w = mx[3][j];
	return (column);
}
