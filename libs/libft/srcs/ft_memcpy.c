/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 00:10:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 14:57:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function copies the first n bytes from memory area src to the memory
 * area dest. The memory areas src and dest must not overlap.
 * @param dest The memory area to receive the src bytes.
 * @param src The memory area to copy.
 * @return A pointer to the memory area dest.
 * */
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
		counter++;
	}
	return (dest);
}
