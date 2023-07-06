/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 12:20:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 20:49:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	get_refractive_index(t_list *containers)
{
	t_object	*obj;

	if (containers == NULL)
		return (1.0);
	obj = ft_lstlast(containers)->content;
	return (obj->material.refractive_index);
}

static void	compute_refractive_index(t_comp *comps, t_intx *intx, t_intxs xs)
{
	t_list		*containers;
	t_list		*node;
	t_object	*obj;

	node = xs.intersections;
	containers = NULL;
	while (node != NULL)
	{
		obj = ((t_intx *)node->content)->object;
		if (node->content == intx)
			comps->n1 = get_refractive_index(containers);
		if (ft_lstfind(containers, obj) != NULL)
			ft_lstremove(&containers, obj);
		else
			ft_lstadd_back(&containers, ft_lstnew(obj));
		if (node->content == intx)
			comps->n2 = get_refractive_index(containers);
		node = node->next;
	}
	ft_lstclear(&containers, NULL);
}

t_comp	prepare_computations(t_intx *inter, t_ray ray, t_intxs xs)
{
	t_comp	comps;

	comps.t = inter->t;
	comps.object = inter->object;
	comps.point = position(comps.t, ray);
	comps.eyev = neg(ray.direction);
	comps.normalv = normal_at(*comps.object, comps.point, *inter);
	if (dotp(comps.eyev, comps.normalv) < 0)
	{
		comps.inside = true;
		comps.normalv = neg(comps.normalv);
	}
	else
		comps.inside = false;
	comps.over_point = add(comps.point, scalar_times(EPSILON, comps.normalv));
	comps.under_point = sub(comps.point, scalar_times(EPSILON, comps.normalv));
	comps.reflectv = reflect(ray.direction, comps.normalv);
	compute_refractive_index(&comps, inter, xs);
	return (comps);
}

t_c3d	color_at(t_ray ray, int remaining)
{
	t_intxs	xs;
	t_intx	*hit_inter;
	t_comp	comps;

	xs = intersect_world(ray);
	hit_inter = hit(xs);
	if (hit_inter == NULL)
	{
		ft_lstclear(&xs.intersections, free);
		return (tcolor(0.0, 0.0, 0.0));
	}
	comps = prepare_computations(hit_inter, ray, xs);
	ft_lstclear(&xs.intersections, free);
	return (shade_hit(comps, remaining));
}
