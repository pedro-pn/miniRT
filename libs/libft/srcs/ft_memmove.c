/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 04:57:31 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 14:50:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function copies the first n bytes from memory area src to the memory
 * area dest. The memory areas src and dest may overlap.
 * @param dest The memory area to receive the src bytes.
 * @param src The memory area to copy.
 * @return A pointer to the memory area dest.
 * */
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	counter;

	if (&((unsigned char *)src)[0] < &((unsigned char *)dest)[0])
		counter = n - 1;
	else
		counter = 0;
	while (counter < (int) n && counter >= 0)
	{
		((unsigned char *)dest)[counter] = ((unsigned char *)src)[counter];
		if (&((unsigned char *)src)[0] < &((unsigned char *)dest)[0])
			counter--;
		else
			counter++;
	}
	return (dest);
}
