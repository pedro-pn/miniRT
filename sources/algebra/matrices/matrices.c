/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 11:21:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/10 15:34:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "algebra.h"

void	set_matrix(t_matrix *matrix, t_set_matrix set_mx)
{
	t_set_matrix_aux	aux_matrix;
	int					i;
	int					j;

	i = 0;
	aux_matrix.set = set_mx;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			(*matrix)[i][j] = (aux_matrix.values)[j + i * 4];
			j++;
		}
		i++;
	}
}

t_bool	matrix_compare(t_matrix mx1, t_matrix mx2)
{
	int	i;
	int	j;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			if (!comp(mx1[i][j], mx2[i][j]))
				return (false);
			j++;
		}
		i++;
	}
	return (true);
}

void	mx_identity(t_matrix *matrix)
{
	set_matrix(matrix, (t_set_matrix){
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1
	});
}
