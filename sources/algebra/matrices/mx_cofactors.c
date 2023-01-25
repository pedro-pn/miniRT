/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_cofactors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:08:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:40:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

static double	cofactor(double _cofactor, int row, int column)
{
	if ((row + column) % 2 == 0)
		return (_cofactor);
	else
		return (-_cofactor);
}

double	mx_minor(t_matrix matrix, int row, int column)
{
	t_matrix	submatrix;

	mx_submatrix(matrix, row, column, &submatrix);
	return (mx_2by2_determinant(submatrix));
}

double	mx_3by3_cofactor(t_matrix matrix, int row, int column)
{
	double	_cofactor;

	_cofactor = mx_minor(matrix, row, column);
	return (cofactor(_cofactor, row, column));
}

double	mx_cofactor(t_matrix matrix, int size, int row, int column)
{
	t_matrix	submatrix;
	double		_cofactor;

	mx_submatrix(matrix, row, column, &submatrix);
	_cofactor = mx_determinant(submatrix, size - 1);
	return (cofactor(_cofactor, row, column));
}
