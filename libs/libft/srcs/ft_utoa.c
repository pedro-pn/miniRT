/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 03:26:53 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/06 23:31:55 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_alg(unsigned int n);
static char	*alloc(unsigned int n);
static int	power(int x, int p);
static void	convert_utoa(unsigned int n, int cf, char *utoa);

/** Allocates with malloc(3) and returns a string representing the unsigned
 * integer received as an argument.
 * @param n The unsigned integer to convert.
 * @return The string representing the unsgined integer. NULL if it fails to
 * allocate.
 * memory.*/
char	*ft_utoa(unsigned int n)
{
	char	*utoa;
	int		cf;
	int		n_alg;

	utoa = alloc(n);
	if (!utoa)
		return (NULL);
	if (n == 0)
	{
		utoa[0] = 48;
		utoa[1] = 0;
		return (utoa);
	}
	n_alg = num_alg(n) - 1;
	cf = power(10, n_alg);
	convert_utoa(n, cf, utoa);
	return (utoa);
}

static int	num_alg(unsigned int n)
{
	unsigned int		num;
	int					counter;

	num = n;
	counter = 0;
	while (num != 0)
	{
		num /= 10;
		counter++;
	}
	return (counter);
}

static char	*alloc(unsigned int n)
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

static void	convert_utoa(unsigned int n, int cf, char *utoa)
{
	int				index;
	unsigned int	div;

	index = 0;
	div = n;
	while (cf != 0)
	{
		utoa[index] = (div / cf) + 48;
		div = div - (div / cf) * cf;
		index++;
		cf /= 10;
	}
	utoa[index] = 0;
}
