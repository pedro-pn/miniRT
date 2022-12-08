/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:36:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 12:19:46 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Iterates the list 'lst' and applies the function 'f' on the content of each
 * node. Creates a new list resulting of the successive applications of the
 * function 'f'. The 'del' function is used to delete the content of a node if
 * needed.
 * @param lst The address of a pointer to a node.
 * @param f The address of the function used to iterate on the list.
 * @param del The address of the function used to delete the content of a node
 * if needed.
 * */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;

	if (lst != NULL)
	{
		new_lst = ft_lstnew((*f)(lst -> content));
		new_lst -> next = ft_lstmap(lst -> next, (*f), (*del));
	}
	else
		return (NULL);
	return (new_lst);
}
