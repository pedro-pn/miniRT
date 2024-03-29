/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle_box.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 01:04:31 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 19:55:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	triangle_bounding_box(t_object triangle)
{
	t_box	box;

	box = empty_bounding_box();
	add_point(&box, triangle.p.p1);
	add_point(&box, triangle.p.p2);
	add_point(&box, triangle.p.p3);
	return (box);
}
