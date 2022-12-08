/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/26 14:28:41 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/26 14:39:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This functions compares two strings pointed to by s1 and s2.
 * @param s1 First string to compare.
 * @param s2 Second string to compare.
 * @return 0 if both strings are equal, a positive integer if s1 is larger than
 * s2, and a negative integer if s1 is shorter than s2.
 * */
int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	counter;
	int		value;

	counter = 0;
	value = 0;
	while (s1[counter] || s2 [counter])
	{
		value = (unsigned char) s1[counter] - (unsigned char) s2[counter];
		if (value != 0)
			return (value);
		counter++;
	}
	return (value);
}
