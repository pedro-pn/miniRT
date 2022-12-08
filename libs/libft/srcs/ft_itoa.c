/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 03:26:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:20:40 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_alg(int n);
static char	*alloc(int n);
static int	power(int x, int p);
static void	convert_itoa(int n, int cf, char *itoa);

/** Allocates with malloc(3) and returns a string representing the integer
 * received as an argument.
 * @param n The integer to convert.
 * @return The string representing the integer. NULL if it fails to allocate
 * memory.*/
char	*ft_itoa(int n)
{
	char	*itoa;
	int		cf;
	int		n_alg;

	itoa = alloc(n);
	if (!itoa)
		return (NULL);
	if (n == 0)
	{
		itoa[0] = 48;
		itoa[1] = 0;
		return (itoa);
	}
	n_alg = num_alg(n) - 1;
	cf = power(10, n_alg);
	convert_itoa(n, cf, itoa);
	return (itoa);
}

static int	num_alg(int n)
{
	int		num;
	int		counter;

	num = n;
	counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static char	*alloc(int n)
{
	char	*s;
	int		counter;

	counter = num_alg(n);
	if (n <= 0)
		counter++;
	s = (char *) malloc((counter * sizeof(char)) + 1);
	if (!s)
		return (NULL);
	return (s);
}

static int	power(int x, int p)
{
	if (p == 0)
		return (1);
	if (p < 0)
		return (0);
	return (x * power(x, p - 1));
}

static void	convert_itoa(int n, int cf, char *itoa)
{
	int	index;
	int	div;
	int	flag;

	index = 0;
	div = n;
	flag = 1;
	if (n < 0)
	{
		itoa[0] = '-';
		flag = -1;
		index++;
	}
	while (cf != 0)
	{
		itoa[index] = flag * (div / cf) + 48;
		div = div - (div / cf) * cf;
		index++;
		cf /= 10;
	}
	itoa[index] = 0;
}
