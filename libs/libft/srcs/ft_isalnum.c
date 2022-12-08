/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 15:52:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 12:23:58 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This function checks whether c is an alphabetic character or a digit.
 * @param c The character to be checked,
 * @return A positive integer if it falls into those categories and 0 if not.
 * */
int	ft_isalnum(int c)
{
	if (c >= 48 && c <= 57)
		return (8);
	else if (c >= 65 && c <= 90)
		return (8);
	else if (c >= 97 && c <= 122)
		return (8);
	return (0);
}
