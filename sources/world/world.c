/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 17:59:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/23 16:51:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <stdio.h>

void	default_world(void)
{
	t_object	*_sphere;

	_sphere = sphere();
	_sphere->material.color = tcolor(0.8, 1.0, 0.6);
	_sphere->material.diffuse = 0.7;
	_sphere->material.specular = 0.2;
	create_object(_sphere);
	_sphere = sphere();
	scaling(vector(0.5, 0.5, 0.5), &_sphere->transform);
	create_object(_sphere);
}

// static void	swap(t_list *list_a, t_list *list_b)
// {

// }

// def quick_sort(a, ini=0, fim=None):
//     fim = fim if fim is not None else len(a)
//     if ini < fim:
//         pp = particao(a, ini, fim)
//         quick_sort(a, ini, pp)
//         quick_sort(a, pp + 1, fim)
//     return a


t_sort	partition(t_list *start, t_list *end)
{
	double	pivot;
	t_intx	*node;
	t_list	*start_node;
	void	*temp;
	t_sort	sort;

	start_node = start; //i
	pivot = ((t_intx *)end->content)->t;
	sort.init = 0;
	while (start != end) //j
	{
		node = start->content;
		if (node->t <= pivot)
		{
			sort.partition = start_node;
			sort.init = 1;
			temp = start->content;
			start->content = start_node->content;
			start_node->content = temp;
			start_node = start_node->next;
		}
		start = start->next;
	}
	temp = start_node->content;
	start_node->content = end->content;
	end->content = temp;
	return (sort);
}

void	quick_sort(t_list *start, t_list *end)
{
	t_sort	sort;

	if (start != end && start != NULL)
	{
		sort = partition(start, end);
		quick_sort(sort.partition, sort.partition);
		if (sort.init == 1)
			quick_sort(sort.partition->next->next, end);
		else
			quick_sort(sort.partition->next, end);
	}
}

t_intxs	intersect_world(t_ray _ray)
{
	t_intxs		result;
	t_intxs		xs;
	t_list		*node_objs;
	t_object	*object;

	node_objs = objects();
	result.intersections = NULL;
	while (node_objs != NULL)
	{
		object = node_objs->content;
		xs = intersect(object, _ray);
		result.count += xs.count;
		ft_lstadd_back(&result.intersections, xs.intersections);
		node_objs = node_objs->next;
	}
	quick_sort(result.intersections, ft_lstlast(result.intersections));
	return (result);
}
