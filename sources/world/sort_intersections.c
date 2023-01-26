/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_intersections.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 21:02:16 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/26 00:02:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	swap(t_intx **a, t_intx **b)
{
	t_intx	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static int	partition(t_intx **intxs_lst, int start, int end)
{
	double	pivot;
	int		i;
	int		j;

	i = start;
	pivot = intxs_lst[end]->t;
	j = start;
	while (j < end)
	{
		if (intxs_lst[j]->t <= pivot)
		{
			swap(&intxs_lst[j], &intxs_lst[i]);
			i++;
		}
		j++;
	}
	swap(&intxs_lst[i], &intxs_lst[end]);
	return (i);
}

static void	quick_sort(t_intx **intxs_lst, int start, int end)
{
	int	_partition;

	if (start < end)
	{
		_partition = partition(intxs_lst, start, end);
		quick_sort(intxs_lst, start, _partition - 1);
		quick_sort(intxs_lst, _partition + 1, end);
	}
}

static void	get_intxs_array(t_intx **intxs, t_list *list)
{
	while (list)
	{
		*intxs = list->content;
		intxs++;
		list = list->next;
	}
}

void	sort_intersections(t_list *intxs_lst)
{
	t_intx	**intxs;
	int		intxs_list_size;
	int		i;

	intxs_list_size = ft_lstsize(intxs_lst);
	intxs = ft_calloc(intxs_list_size, sizeof(*intxs));
	get_intxs_array(intxs, intxs_lst);
	quick_sort(intxs, 0, intxs_list_size - 1);
	i = 0;
	while (intxs_lst)
	{
		intxs_lst->content = intxs[i];
		i++;
		intxs_lst = intxs_lst->next;
	}
	free(intxs);
}
