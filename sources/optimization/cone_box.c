/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_box.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 16:04:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/28 16:12:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	cone_bounding_box(t_object obj)
{
	t_box	box;
	double	limit;

	limit = max(fabs(obj.minimum), fabs(obj.maximum));
	box.min = point(-limit, obj.minimum, -limit);
	box.max = point(limit, obj.maximum, limit);
	return (box);
}
