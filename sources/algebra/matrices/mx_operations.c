/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mx_operations.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 12:34:13 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/10 16:11:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	mx_product(t_matrix mx1, t_matrix mx2, t_matrix *result)
{
	int		i;
	int		j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[i][j] = dotp(mx_get_row(mx1, i), mx_get_column(mx2, j));
			j++;
		}
		i++;
	}
}

t_t3d	mx_tuple_product(t_matrix mx, t_t3d tuple)
{
	t_t3d	result;

	result.x = dotp(mx_get_row(mx, 0), tuple);
	result.y = dotp(mx_get_row(mx, 1), tuple);
	result.z = dotp(mx_get_row(mx, 2), tuple);
	result.w = dotp(mx_get_row(mx, 3), tuple);
	return (result);
}

void	mx_transpose(t_matrix matrix, t_matrix *result)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*result)[i][j] = matrix[j][i];
			j++;
		}
		i++;
	}
}