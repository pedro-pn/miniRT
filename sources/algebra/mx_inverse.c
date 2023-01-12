/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:09:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/12 11:02:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

double	mx_minor(t_matrix matrix, int row, int column)
{
	t_matrix	submatrix;

	mx_submatrix(matrix, row, column, &submatrix);
	return (mx_2by2_determinant(submatrix));
}

double	mx_3by3_cofactor(t_matrix matrix, int row, int column)
{
	double	cofactor;
	int		id;

	cofactor = mx_minor(matrix, row, column);
	id = row + column;
	if (id % 2 == 0)
		return (cofactor);
	else
		return (-cofactor);
}

double	mx_4by4_cofactor(t_matrix matrix, int row, int column)
{
	t_matrix	sub_matrix;
	double		cofactor;
	int			id;

	mx_submatrix(matrix, row, column, &sub_matrix);
	cofactor = mx_3by3_determinant(sub_matrix);
	id = row + column;
	if (id % 2 == 0)
		return (cofactor);
	else
		return (-cofactor);
}
