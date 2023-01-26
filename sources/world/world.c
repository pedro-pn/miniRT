/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 23:13:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	default_world(void)
{
	t_object	*_sphere;

	world()->objects = NULL;
	_sphere = sphere();
	_sphere->material.color = tcolor(0.8, 1.0, 0.6);
	_sphere->material.diffuse = 0.7;
	_sphere->material.specular = 0.2;
	create_object(_sphere);
	_sphere = sphere();
	scaling(vector(0.5, 0.5, 0.5), &_sphere->transform);
	create_object(_sphere);
}

t_intxs	intersect_world(t_ray _ray)
{
	t_intxs		result;
	t_intxs		xs;
	t_list		*node_objs;
	t_object	*object;

	node_objs = objects();
	result.intersections = NULL;
	result.count = 0;
	while (node_objs != NULL)
	{
		object = node_objs->content;
		xs = intersect(object, _ray);
		result.count += xs.count;
		ft_lstadd_back(&result.intersections, xs.intersections);
		node_objs = node_objs->next;
	}
	if (result.intersections != NULL)
		sort_intersections(result.intersections);
	return (result);
}
