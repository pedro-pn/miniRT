/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 18:11:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:11:43 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function concatenates src string to dest and it terminates adding a
 * '\0' byte to dest.
 * @param dst The prefix string. dst must be NUL-terminated.
 * @param src The suffix string. src must be NUL-terminated.
 * @param size The total length of the final dest string. It must include an
 * additional byte for NUL.
 * @return The function returns the total length of the string it tried to
 * create: dest length + src lengt.
 * */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	int		counter;
	size_t	length_dst;
	size_t	length_src;
	int		counter2;

	counter = 0;
	length_dst = 0;
	length_src = 0;
	while (dst[length_dst] && length_dst < size)
		length_dst++;
	while (src[length_src])
		length_src++;
	counter2 = length_dst;
	if (length_dst < size)
	{
		while ((counter2 < (int) size - 1 || (int) size < 0) && src[counter])
		{
			dst[counter2] = src[counter];
			counter++;
			counter2++;
		}
		dst[counter2] = '\0';
	}
	return (length_dst + length_src);
}
