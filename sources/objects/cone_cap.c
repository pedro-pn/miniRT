/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_cap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:58:28 by pedro             #+#    #+#             */
/*   Updated: 2023/04/04 19:58:54 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bool	check_cap(t_ray ray, double t, double y)
{
	double	x;
	double	z;

	x = ray.origin.x + t * ray.direction.x;
	z = ray.origin.z + t * ray.direction.z;
	return (pow(x, 2) + pow(z, 2) <= pow(y, 2));
}

void	intersect_cone_caps(t_object *cone, t_ray ray, t_intxs *xs)
{
	double	t;

	if (cone->closed == false || comp(ray.direction.y, 0))
		return;
	t = (cone->minimum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cone->minimum))
		create_intersection(xs, t, cone);
	t = (cone->maximum - ray.origin.y) / ray.direction.y;
	if (check_cap(ray, t, cone->maximum))
		create_intersection(xs, t, cone);
}
