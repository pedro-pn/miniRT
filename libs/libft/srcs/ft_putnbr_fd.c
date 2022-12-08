/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:27:43 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:41:53 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** @brief Outputs the integer 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.*/
void	ft_putnbr_fd(int n, int fd)
{
	char	num;
	int		flag;

	flag = 1;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		flag = -1;
	}
	num = n % 10 * flag + 48;
	if (n / 10 != 0)
		ft_putnbr_fd(n / 10 * flag, fd);
	ft_putchar_fd(num, fd);
}
