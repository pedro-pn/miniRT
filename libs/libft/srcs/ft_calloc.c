/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 17:02:09 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:04:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function allocates nmemb times size bytes of heap memory and set all
 * allocated bytes to 0.
 * @param nmemb The number of members to allocate.
 * @param size The size of each member to allocate.
 * @return A pointer to the memory area allocated or NULL if it fails to
 * allocate.
 * */
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (size != 0)
	{
		if (nmemb > INT_MAX / size)
			return (NULL);
	}
	ptr = malloc(nmemb * size);
	if (ptr == NULL)
		return (ptr);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}
