/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 17:10:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 15:59:59 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** This funciton converts the first portion of the string pointed to by nptr
 * into an integer.
 * @param nptr The string to be converted.
 * @return The converted integer or 0 on error.
 * */
int	ft_atoi(const char *nptr)
{
	int	atoi;
	int	sign;

	sign = 1;
	atoi = 0;
	while ((*nptr) && (*nptr == '\n' || *nptr == '\t'
			|| *nptr == '\r' || *nptr == '\f'
			|| *nptr == '\v' || *nptr == 32))
		++nptr;
	if (*nptr == '-')
		sign = -1;
	if (*nptr == '+' || *nptr == '-')
		++nptr;
	while (*nptr && *nptr >= 48 && *nptr <= 57)
	{
		atoi = (atoi * 10) + (*nptr - 48);
		++nptr;
	}
	return (atoi * sign);
}
