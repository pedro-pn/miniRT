/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_box.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:39:39 by pedro             #+#    #+#             */
/*   Updated: 2023/04/13 17:20:03 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	plane_bounding_box(t_object plane)
{
	t_box	box;

	(void)plane;
	box.min = point(-INF, 0, -INF);
	box.max = point(INF, 0, INF);
	return (box);
}
