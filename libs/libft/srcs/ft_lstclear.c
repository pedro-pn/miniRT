/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:56:06 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 00:04:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Deletes and frees the given node and every successor of that node, using the
 * function 'del' and free(3). The pointer to the list is set to NULL.
 * @param lst The address of a pointer to a node.
 * @param del The address of the function used to delete the content of the
 * node.*/
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (*lst != 0)
	{	
		(*del)((*lst)-> content);
		ft_lstclear(&((*lst)-> next), (*del));
		free(*lst);
	}
	*lst = NULL;
}
