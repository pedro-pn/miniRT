/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wavefront_faces_normal.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 00:47:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/21 22:37:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (ft_arradd_int(&face->n_indexes, normal, face->n_indexes_size))
		return (clean_faces(face), false);
	face->n_indexes_size++;
	return (true);
}
