/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 22:05:28 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:47:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Allocates with malloc(3) and returns a new node of t_list. The member
 * variable 'content' is initialized with the value of the parameter ’content’.
 * The variable 'next' is initialized to NULL.
 * @param content The content to create the node with.
 * @return Returns a pointer to the t_list new node.*/
t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (!list)
		return (NULL);
	list -> content = content;
	list -> next = NULL;
	return (list);
}
