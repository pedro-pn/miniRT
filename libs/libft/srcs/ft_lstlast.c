/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:35:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:56:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Returns the last node of a t_list.
 * @param lst The beginning of the list.
 * @return A pointer to the last node of the list.*/
t_list	*ft_lstlast(t_list *lst)
{
	if (lst != NULL)
	{
		if (lst -> next == NULL)
			return (lst);
		return (ft_lstlast(lst -> next));
	}
	return (lst);
}
