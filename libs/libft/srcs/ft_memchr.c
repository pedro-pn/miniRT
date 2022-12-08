/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 00:36:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:40:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function checks whether c is present in the first n bytes of the memory
 * area pointed to by s.
 * @param s The memory area on which to check.
 * @param c The byte to be checked.
 * @param n The number of bytes to be checked.
 * @return A pointer to c in the s memmory area or NULL if s does not contain c.
 * */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		if (((unsigned char *)s)[counter] == (unsigned char )c)
			return (&((unsigned char *)s)[counter]);
		counter++;
	}
	return (NULL);
}
