/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 20:44:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 14:57:10 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** The function ft_memset fills the first n bytes of the memory area pointed
 * to by s with the byte c.
 * @param s The address of the memory area.
 * @param c The byte to fill the memory area pointed to by s.
 * @param n The total number of bytes to fill s.
 * @return A pointer to the memomry area s.
 * */
void	*ft_memset(void *s, int c, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *) s)[counter] = (unsigned char) c;
		counter++;
	}
	return (s);
}
