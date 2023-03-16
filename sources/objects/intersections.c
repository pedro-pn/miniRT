/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:42:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/16 18:25:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intx	*new_intersection(double t, t_object *obj)
{
	t_intx	*inter;

	inter = ft_calloc(1, sizeof(*inter));
	inter->object = obj;
	inter->t = t;
	return (inter);
}

void	create_intersection(t_intxs *xs, double t, t_object *obj)
{
	t_intx	*inter;

	xs->count++;
	inter = new_intersection(t, obj);
	ft_lstadd_back(&xs->intersections, ft_lstnew(inter));
}

t_intxs	empty_intersection(void)
{
	t_intxs	xs;

	xs.count = 0;
	xs.intersections = NULL;
	return (xs);
}
