/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront_faces_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:47:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 16:36:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	add_normal_index(t_face *face, int normal_index)
{
	face->n_indexes = ft_realloc(face->n_indexes, sizeof(normal_index)
			* face->n_indexes_size,
				(face->n_indexes_size + 1) * sizeof(normal_index));
	face->n_indexes[face->n_indexes_size] = normal_index;
	face->n_indexes_size++;
}

t_bool	parse_face_normal(t_face *face, char **line, size_t n_count)
{
	int	normal;

	(*line)++;
	while(ft_isdigit(**line))
		(*line)++;
	if (**line != '/')
		return (false);
	(*line)++;
	normal = ft_atoi(*line);
	if (normal == 0 || normal > (int) n_count)
		return (clean_faces(face), false);
	add_normal_index(face, normal);
	return (true);
}
