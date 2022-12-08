/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 21:50:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 14:21:15 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This function fills the first n bytes of the memory area pointed to by s
 * with 0.
 * @param s The memory area to fill.
 * @param n The total number of bytes to fill s
 * */
void	ft_bzero(void *s, size_t n)
{
	size_t	counter;

	counter = 0;
	while (counter < n)
	{
		((unsigned char *) s)[counter] = '\0';
		counter++;
	}
}
