/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 03:49:42 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 12:24:51 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This function checks whether c is an alphabetic character.
 * @param c The character to be checked.
 * @return A positive integer if c is an alphabetic character and 0 if not.
 * */
int	ft_isalpha(int c)
{
	if (c >= 65 && c <= 90)
		return (1024);
	else if (c >= 97 && c <= 122)
		return (1024);
	return (0);
}
