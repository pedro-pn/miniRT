/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:03:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 00:02:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Takes as a parameter a node and frees the memory of the node's content using
 * the function 'del' given as a parameter and free the node. The memory of
 * 'next' will not be freed.
 * @param lst The node to free.
 * @param del the address of the function used to delete the content of the
 * node.*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && (*del))
	{
		(*del)(lst->content);
		free(lst);
	}
}
