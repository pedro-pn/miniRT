/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:32:22 by pedro             #+#    #+#             */
/*   Updated: 2023/04/13 16:43:25 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	sphere_bounding_box(t_object sphere)
{
	t_box	box;

	(void)sphere;
	box.min = point(-1, -1, -1);
	box.max = point(1, 1, 1);
	return (box);
}
