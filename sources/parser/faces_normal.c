/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   faces_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:47:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 15:23:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	add_normal_index(t_face *face, int normal_index)
{
	face->n_indexes = ft_realloc(face->n_indexes, sizeof(normal_index)
			* face->normals_size,
				(face->normals_size + 1) * sizeof(normal_index));
	face->n_indexes[face->normals_size] = normal_index;
	face->normals_size++;
}

t_bool	make_face_normals(t_parser *parser, t_face *face, char **line)
{
	int	normal;

	(*line)++;
	while(ft_isdigit(**line))
		(*line)++;
	if (**line != '/')
		return (false);
	(*line)++;
	normal = ft_atoi(*line);
	if (normal == 0 || normal > (int) parser->n_count)
		return (clean_faces(face), false);
	add_normal_index(face, normal);
	return (true);
}
