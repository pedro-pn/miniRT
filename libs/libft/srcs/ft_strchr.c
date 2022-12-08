/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:12:33 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:14:49 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function checks whether c is present in the string pointed to by s.
 * @param s The string on which to check.
 * @param c The character to be checked.
 * @return A pointer to the first ocurrence of c in s. If c is not found in s
 * string, NULL is returned.
 * */
char	*ft_strchr(const char *s, int c)
{
	int		counter;
	int		len_s;

	counter = 0;
	len_s = (int) ft_strlen(s);
	while (counter <= len_s)
	{
		if (s[counter] == (unsigned char) c)
			return (&((char *)s)[counter]);
		counter++;
	}
	return (NULL);
}
