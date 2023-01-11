/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 13:09:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/11 13:12:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

double	mx_minor(t_matrix matrix, int row, int column)
{
	t_matrix	submatrix;

	mx_submatrix(matrix, row, column, &submatrix);
	return (mx_2by2_determinant(submatrix));
}

double	mx_cofactor(t_matrix matrix, int row, int column)
{
	double	minor;
	int		id;

	minor = mx_minor(matrix, row, column);
	id = row + column;
	if (id % 2 == 0)
		return (minor);
	else
		return (-minor);
}
