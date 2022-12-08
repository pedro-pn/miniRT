/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 16:01:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 12:24:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/** This functions checks whether c is an ASCII character (0–127).
 * @param c The character to be checked.
 * @return A positive integer if c is an ASCII character and 0 if not.
 * */
int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
