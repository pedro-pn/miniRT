/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/27 20:52:21 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/27 21:00:40 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	cylinder_bounding_box(t_object cylinder)
{
	t_box	box;

	box.max = point(1, cylinder.maximum, 1);
	box.min = point(-1, cylinder.minimum, -1);
	return (box);
}
