/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:58:30 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 20:57:34 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Allocates with malloc(3) and returns a substring from the string ’s’.
* The substring begins at index 'start' and it is of maximum size 'len'.
* @param s The string from which to create the substring.
* @param start The start index of the substring in the string 's'.
* @param len The maximum length of the substring.
* @return The substring or NULL if it fails to allocate memory.*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	int		mem;
	size_t	s_len;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	mem = s_len - start;
	if (mem > (int) len)
		mem = len;
	if (mem <= 0)
		mem = 0;
	sub = (char *) malloc((mem * sizeof(char)) + 1);
	if (sub == NULL)
		return (NULL);
	sub[mem] = 0;
	while (mem > 0)
	{
		sub[mem - 1] = s[start + mem - 1];
		mem--;
	}
	return (sub);
}
