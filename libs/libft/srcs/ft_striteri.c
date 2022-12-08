/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 19:08:27 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:28:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** Applies the function 'f' on each character of the string passed as argument,
 * passing its index as first argument. Each character is passed by address to
 * 'f' to be modified if necessary.
 * @param s The string on which to iterate.
 * @param f The function to apply to each character.*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	index;

	index = 0;
	if (!s || !(*f))
		return ;
	while (s[index])
	{
		(*f)(index, &s[index]);
		index++;
	}
}
