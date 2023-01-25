/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 00:14:44 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:43:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_intx	*hit(t_intxs intersections)
{
	t_intx	*result;
	t_intx	*inter;
	t_list	*inter_lst;
	double	t;

	t = __DBL_MAX__;
	result = NULL;
	inter_lst = intersections.intersections;
	while (inter_lst != NULL)
	{
		inter = inter_lst->content;
		if (inter->t < t && inter->t >= 0)
		{	
			t = inter->t;
			result = inter;
		}	
		inter_lst = inter_lst->next;
	}
	return (result);
}
