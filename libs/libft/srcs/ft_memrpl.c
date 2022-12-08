/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrpl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 13:22:25 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:38:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function replaces the first n bytes of the memory area pointed to by
 * s every ocurrence of old with new.
 * @param s The memory area on which to replace.
 * @param old The byte to be replaced.
 * @param new The byte to replace old.
 * @param n The number of bytes to replace in s.
 * @return A pointer to the memory area s.
 * */
void	*ft_memrpl(char *s, int old, int new, size_t n)
{
	int	index;

	index = 0;
	if ((unsigned char) old == (unsigned char) new)
		return (s);
	while (index < (int) n)
	{
		if (s[index] == (unsigned char) old)
			s[index] = (unsigned char) new;
		index++;
	}
	return (s);
}
