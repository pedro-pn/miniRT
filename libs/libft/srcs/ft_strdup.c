/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 19:08:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:19:19 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function copies the s string to a new allocated memory area. The memory
 * is obtained with malloc(3) and can be freed with free(3).
 * @param s The string to be copied.
 * @return A pointer to the new string or NULL if it fails.
 * */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	size_t	s_len;
	size_t	counter;

	s_len = ft_strlen(s);
	counter = 0;
	ptr = (char *) malloc((s_len * sizeof(char)) + 1);
	if (!ptr)
		return (NULL);
	while (counter < s_len + 1)
	{
		ptr[counter] = s[counter];
		counter++;
	}
	return (ptr);
}
