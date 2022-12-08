/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:39:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:25:03 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Applies the function 'f' to each character of the string 's', and passing
 * its index as first argument to create a new string with malloc(3) resulting
 * from successive applications of 'f'.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.
 * @return The string created from the sucessive applications of 'f'. Returns
 * NULL if it fails to allocate memory.*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	s_len;
	size_t	index;
	char	*map_str;

	if (s == NULL || (*f) == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	map_str = (char *) malloc((s_len * sizeof(char)) + 1);
	if (!map_str)
		return (NULL);
	index = 0;
	while (index < s_len)
	{
		map_str[index] = (*f)(index, s[index]);
		index++;
	}
	map_str[index] = 0;
	return (map_str);
}
