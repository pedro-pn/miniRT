/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 18:16:48 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/09 18:34:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	calculate_triangle_normal(t_object *t)
{
	t->e1 = sub(t->p2, t->p1);
	t->e2 = sub(t->p3, t->p1);
	t->normalv = normalize(cross(t->e2, t->e1));
}

t_v3d	triangle_normal_at(t_object obj, t_p3d point)
{
	(void)point;
	return (obj.normalv);
}

t_object	*triangle(t_p3d p1, t_p3d p2, t_p3d p3)
{
	t_object	*_triangle;

	_triangle = ft_calloc(1, sizeof(*_triangle));
	_triangle->type = TRIANGLE;
	mx_identity(&_triangle->transform);
	_triangle->material = material();
	_triangle->clean = free;
	_triangle->p1 = p1;
	_triangle->p2 = p2;
	_triangle->p3 = p3;
	_triangle->normal = triangle_normal_at;
	calculate_triangle_normal(_triangle);
	return (_triangle);
}
