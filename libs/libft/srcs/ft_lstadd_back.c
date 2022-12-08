/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 00:54:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:58:57 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Adds the node 'new' at the end of a t_list.
 * @param lst The address of a pointer to the first node of the list.
 * @param new The address of a pointer to the node to be added to the list.*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	if (new == NULL)
		return ;
	if (*lst != NULL)
		ft_lstadd_back(&((*lst)-> next), new);
	else
		*lst = new;
}
