/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_submatrix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:18:40 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/11 12:39:44 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

static void	mx_switch_row_end(t_matrix *mx, int row)
{
	while (row < 3)
	{
		mx_switch_rows(mx, row, row + 1);
		row++;
	}
}

static void	mx_switch_column_end(t_matrix *mx, int column)
{
	while (column < 3)
	{
		mx_switch_columns(mx, column, column + 1);
		column++;
	}
}

void	mx_submatrix(t_matrix mx, int row, int column, t_matrix *result)
{
	int	i;

	mx_copy(mx, result);
	mx_switch_row_end(result, row);
	mx_switch_column_end(result, column);
	ft_bzero(&(*result)[3], 4 * sizeof(double));
	i = 0;
	while (i < 3)
	{
		ft_bzero(&(*result)[i][3], sizeof(double));
		i++;
	}
}

double	mx_minor(t_matrix matrix, int row, int column)
{
	t_matrix	submatrix;

	mx_submatrix(matrix, row, column, &submatrix);
	return (mx_2by2_determinant(submatrix));
}

void	inspect_matrix(t_matrix matrix)
{
	int	i;
	int	j;

	i = 0;
	ft_putendl_fd("MATRIX:", 1);
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			ft_putdouble_fd(matrix[i][j], 1, 3);
			ft_putstr_fd(", ", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}
