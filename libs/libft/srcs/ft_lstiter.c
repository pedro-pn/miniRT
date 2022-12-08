/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 23:25:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 00:05:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/** Iterates the t_list 'lst' and applies the function 'f' on the content of
 * each node.
 * @param lst The address of a pointer to a node.
 * @param f The address of a function used to iterate on the list.*/
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != 0)
	{
		(*f)(lst -> content);
		ft_lstiter((lst -> next), (*f));
	}
}
