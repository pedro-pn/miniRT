/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:31:32 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 15:34:45 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief Copies the src string to dest and returns a 
 * pointer to the end of dest.
 * @param dest The string to receive the copy.
 * @param src The string to be copied.
 * @return Return a pointer to the end of the string dest
*/
char	*ft_strcpy_end(char *dest, char *src)
{
	while (*src != '\0')
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}
