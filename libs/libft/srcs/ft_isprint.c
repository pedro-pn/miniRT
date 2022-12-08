/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 17:24:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 12:24:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This funcitons checks whether c is an ASCII printable character (32–126).
 * @param c The character to be checked.
 * @return A positive integer if c is an ASCII printable character and 0 if not.
 * */
int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (16384);
	return (0);
}
