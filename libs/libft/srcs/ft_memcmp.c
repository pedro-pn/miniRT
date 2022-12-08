/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:38:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:43:23 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function compares the first n bytes of the two memory areas pointed to
 * by s1 and s2.
 * @param s1 A pointer to the memory area.
 * @param s2 A pointer to the memory area.
 * @param n The number of bytes to be compared.
 * @return 0 if they s1 and s2 equal, a positive integer if s1 is larger than s2
 * and a negative integer if s1 is shorter than s2.
 * */
int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	int		value;
	size_t	counter;

	counter = 0;
	value = 0;
	while (counter < n)
	{
		value = ((unsigned char *)s1)[counter] - ((unsigned char *)s2)[counter];
		if (value != 0)
			return (value);
		counter++;
	}
	return (value);
}
