/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_inverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 13:45:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:40:29 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

t_bool	mx_is_invertible(t_matrix matrix, int size)
{
	if (comp(mx_determinant(matrix, size), 0))
		return (false);
	return (true);
}

static void	mx_make_inverse(t_matrix matrix, double det, t_matrix *result)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[j][i] = mx_cofactor(matrix, 4, i, j) / det;
			j++;
		}
		i++;
	}
}

void	mx_inverse(t_matrix matrix, t_matrix *result)
{
	double	determinant;

	if (!mx_is_invertible(matrix, 4))
	{
		result = NULL;
		return ;
	}
	determinant = mx_determinant(matrix, 4);
	mx_make_inverse(matrix, determinant, result);
}
