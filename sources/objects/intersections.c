/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersections.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 12:42:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/13 10:34:28 by ppaulo-d         ###   ########.fr       */
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

void	create_intersection(t_list **list, double t, t_object *obj)
{
	t_intx	*inter;

	inter = new_intersection(t, obj);
	ft_lstadd_back(list, ft_lstnew(inter));
}

t_intxs	empty_intersection(void)
{
	t_intxs	xs;

	xs.count = 0;
	xs.intersections = NULL;
	return (xs);
}
