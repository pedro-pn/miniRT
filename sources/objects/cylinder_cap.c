/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_cap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 16:46:00 by pedro             #+#    #+#             */
/*   Updated: 2023/04/04 19:47:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_cap(t_ray ray, double t)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= 1);
}

void	intersect_caps_cy(t_object *cylinder, t_ray ray, t_intxs *xs)
{
	double	t;

	if (cylinder->closed == false || comp(ray.direction.y, 0))
		return;
	t = (cylinder->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		create_intersection(xs, t, cylinder);
	t = (cylinder->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t))
		create_intersection(xs, t, cylinder);
}
