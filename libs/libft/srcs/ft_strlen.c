/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:33:02 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 14:13:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Calculates the length of the string pointed to by str, excluding the '\0'
 * byte.
 * @param str The string on which to calculate the length. Must be
 * NUL-terminated.
 * @return The total length (number of bytes) of the string pointed to by str.
 * */
size_t	ft_strlen(const char *str)
{
	size_t	counter;

	counter = 0;
	while (str[counter])
		counter++;
	return (counter);
}
