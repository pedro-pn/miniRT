/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:07:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:50:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This function returns the lowercase c character if c is an uppercase
 * alphabetic character.
 * @param c The character to be converted.
 * @return The lowercase character c. If c is not an uppercase alphabetic
 * character, c is returned.
 * */
int	ft_tolower(int c)
{
	if (c >= 65 && c <= 90)
		return (c + 32);
	return (c);
}
