/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/12 11:36:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

double	mx_2by2_determinant(t_matrix matrix)
{
	double	ad;
	double	bc;

	ad = matrix[0][0] * matrix[1][1];
	bc = matrix[0][1] * matrix [1][0];
	return (ad - bc);
}

double	mx_determinant(t_matrix matrix, int size)
{
	double	determinant;
	int		j;

	if (size == 2)
		return (mx_2by2_determinant(matrix));
	j = 0;
	determinant = 0;
	while (j < size)
	{
		determinant += mx_cofactor(matrix, size, 0, j) * matrix[0][j];
		j++;
	}
	return (determinant);
}
