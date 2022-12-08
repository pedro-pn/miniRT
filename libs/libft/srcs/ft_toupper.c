/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 22:02:20 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:50:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This function returns the uppercase c character if c is a lowercase
 * alphabetic character.
 * @param c The character to be converted.
 * @return The uppercase character c. If c is not an lowercase alphabetic
 * character, c is returned.
 * */
int	ft_toupper(int c)
{
	if (c >= 97 && c <= 122)
		return (c - 32);
	return (c);
}
