/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfloat_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 15:03:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/04 15:38:32 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	power(int x, int p);

/** @brief Outputs the float 'n' to the given file descriptor.
 * @param n The integer to output.
 * @param fd The file descriptor on which to write.*/
void	ft_putdouble_fd(double n, int fd, int res)
{
	int		intpart;
	double	fpart;
	int		fi_part;

	intpart = (int) n;
	fpart = n - (double) intpart;
	if (fpart < 0)
		fpart *= -1.0;
	fi_part = (int) (fpart * power(10, res));
	ft_putnbr_fd(intpart, fd);
	ft_putchar_fd('.', fd);
	ft_putnbr_fd(fi_part, fd);
}

static int	power(int x, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (x * power(x, p - 1));
}