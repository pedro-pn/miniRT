/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 21:51:07 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/13 10:34:41 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	void	check_axis(double origin, double direction, double *t)
{
	double	tmin_num;
	double	tmax_num;

	tmin_num = (-1 - origin);
	tmax_num = (1 - origin);
	if ((abs_double(direction) >= EPSILON))
	{
		t[0] = tmin_num / direction;
		t[1] = tmax_num / direction;
	}
	else
	{
		t[0] = tmin_num * __DBL_MAX__;
		t[1] = tmax_num * __DBL_MAX__;
	}
	if (t[0] > t[1])
		ft_swap_double(&t[0], &t[1]);
}

static void	get_cube_t(t_p3d min, t_p3d max, double *t)
{
	t_tuple min_tuple;
	t_tuple	max_tuple;
	int		i;

	t[0] = -__DBL_MAX__;
	t[1] = __DBL_MAX__;
	min_tuple.point = min;
	max_tuple.point = max;
	i = 0;
	while (i < 3)
	{
		if (min_tuple.points[i] > t[0])
			t[0] = min_tuple.points[i];
		if (max_tuple.points[i] < t[1])
			t[1] = max_tuple.points[i];
		i++;
	}
}

t_intxs	intersect_cube(t_object *cube, t_ray ray)
{
	t_intxs	xs;
	t_p3d	min;
	t_p3d	max;
	double	t[2];

	xs.intersections = NULL;
	check_axis(ray.origin.x, ray.direction.x, t);
	min.x = t[0];
	max.x = t[1];
	check_axis(ray.origin.y, ray.direction.y, t);
	min.y = t[0];
	max.y = t[1];
	check_axis(ray.origin.z, ray.direction.z, t);
	min.z = t[0];
	max.z = t[1];
	get_cube_t(min, max, t);
	if (t[0] > t[1])
		return (empty_intersection());
	xs.count = 2;
	create_intersection(&xs.intersections, t[0], cube);
	create_intersection(&xs.intersections, t[1], cube);
	return (xs);
}

t_object	*cube(void)
{
	t_object	*_cube;

	_cube = ft_calloc(1, sizeof(*_cube));
	mx_identity(&_cube->transform);
	_cube->intersect = intersect_cube;
	return (_cube);
}
