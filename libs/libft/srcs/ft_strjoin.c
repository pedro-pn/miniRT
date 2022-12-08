/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 21:08:56 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 21:02:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Allocates with malloc(3) and returns a new string, which is the result of
 * the concatenation of ’s1’ and ’s2’.
 * @param s1 The prefix string.
 * @param s2 The suffix string.
 * @return The new string. NULL if it fails to allocate memory.*/
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len += ft_strlen(s2);
	str = (char *) malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (*s1 != 0)
	{
		*str = *s1;
		str++;
		s1++;
	}
	while (*s2 != 0)
	{
		*str = *s2;
		str++;
		s2++;
	}
	*str = 0;
	return (str - len);
}
