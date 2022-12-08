/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 16:14:58 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:48:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function search for the string little inside the string big up to len
 * bytes.
 * @param big The string on which to search little.
 * @param little The string to be found in big.
 * @param len The number of bytes to search in big.
 * @return If little is an empty string, big is returned. If big contains
 * little, a pointer to the first character of little
 * in big is returned. If big does not contain little, NULL is returned.
 * */
char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	counter;
	size_t	little_len;
	char	*big_ptr;

	counter = 0;
	little_len = ft_strlen(little);
	if (little[counter] == '\0')
		return ((char *)big);
	if (!*big)
		return (NULL);
	while (counter < len)
	{
		if ((! ft_strncmp(&big[counter], little, little_len))
			&& little_len <= len - counter)
		{
			big_ptr = &((char *)big)[counter];
			return (big_ptr);
		}
		counter++;
	}
	return (NULL);
}
