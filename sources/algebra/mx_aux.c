/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:56:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/10 22:22:24 by ppaulo-d         ###   ########.fr       */
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

void	mx_copy(t_matrix matrix, t_matrix *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[i][j] = matrix[i][j];
			j++; 
		}
		i++;
	}
}

void	mx_switch_rows(t_matrix *matrix, int row_1, int row_2)
{	
	t_t3d			temp_row;

	temp_row = mx_get_row(*matrix, row_1);
	(*matrix)[row_1][0] = (*matrix)[row_2][0];
	(*matrix)[row_1][1] = (*matrix)[row_2][1];
	(*matrix)[row_1][2] = (*matrix)[row_2][2];
	(*matrix)[row_1][3] = (*matrix)[row_2][3];
	(*matrix)[row_2][0] = temp_row.x;
	(*matrix)[row_2][1] = temp_row.y;
	(*matrix)[row_2][2] = temp_row.z;
	(*matrix)[row_2][3] = temp_row.w;
}

void	mx_switch_columns(t_matrix *matrix, int column_1, int column_2)
{	
	t_t3d	temp_column;

	temp_column = mx_get_column(*matrix, column_1);
	(*matrix)[0][column_1] = (*matrix)[0][column_2];
	(*matrix)[1][column_1] = (*matrix)[1][column_2];
	(*matrix)[2][column_1] = (*matrix)[2][column_2];
	(*matrix)[3][column_1] = (*matrix)[3][column_2];
	(*matrix)[0][column_2] = temp_column.x;
	(*matrix)[1][column_2] = temp_column.y;
	(*matrix)[2][column_2] = temp_column.z;
	(*matrix)[3][column_2] = temp_column.w;
}
