/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_determinant.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:53:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/12 11:00:02 by ppaulo-d         ###   ########.fr       */
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

double	mx_3by3_determinant(t_matrix matrix)
{
	double	determinant;
	int		j;

	determinant = 0;
	j = 0;
	while (j < 3)
	{
		determinant += mx_3by3_cofactor(matrix, 0, j) * matrix[0][j];
		j++;
	}
	return (determinant);
}

double	mx_4by4_determinant(t_matrix matrix)
{
	double	determinant;
	int		j;

	determinant = 0;
	j = 0;
	while (j < 4)
	{
		determinant += mx_4by4_cofactor(matrix, 0, j) * matrix[0][j];
		j++;
	}
	return (determinant);
}
