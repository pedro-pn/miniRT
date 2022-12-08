/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:43:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:16:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This funciton checks whether c is present in the string pointed to by s.
 * @param s The string on which to check.
 * @param c The character to be checked.
 * @return A pointer to the last ocurrence of c in s. If c is not found in s
 * string, NULL is returned.
 * */
char	*ft_strrchr(const char *s, int c)
{
	int	counter;

	counter = (int) ft_strlen(s);
	while (counter >= 0)
	{
		if ((unsigned char) s[counter] == (unsigned char) c)
			return (&((char *)s)[counter]);
		counter--;
	}
	return (NULL);
}
