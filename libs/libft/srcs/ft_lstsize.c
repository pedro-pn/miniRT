/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:12:38 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:54:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Counts the number of nodes in a t_list.
 * @param lst The beginning of the list.
 * @return The length of the list.*/
int	ft_lstsize(t_list *lst)
{
	if (lst != NULL)
		return (1 + ft_lstsize(lst -> next));
	return (0);
}
