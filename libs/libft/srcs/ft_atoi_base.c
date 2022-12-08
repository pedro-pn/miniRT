/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/06 21:38:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 16:02:31 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	base_index(char n, char *base);
static int	get_base(char *base);
static int	power(int base, int n);
static char	*input_check(char *str, char *base);

/** This function converts the first portion of the string pointed to by str
 * into an integer. The portion to be converted in str may be in any given base,
 * since base does not contain repeated characteres and the '+' '-' symbols.
 * @param str The string to be converted.
 * @param base The string representing the base of the number in str.
 * @return The converted integer or 0 on error.
 * */
int	ft_atoi_base(char *str, char *base)
{
	int		nbr;
	int		base_n;
	int		str_len;
	int		counter;
	char	*nptr;

	if (!str || !base)
		return (0);
	nbr = 0;
	base_n = get_base(base);
	counter = -1;
	nptr = input_check(str, base);
	str_len = ft_strlen(nptr);
	while (counter++, str_len--, str_len >= 0)
	{
		nbr += power(base_n, counter) * base_index(nptr[str_len], base);
		if (!ft_strchr(base, nptr[str_len]) && str_len != 0)
		{
			nbr = 0;
			counter = -1;
		}
	}
	if (nptr[str_len + 1] == '-')
		return (-nbr);
	return (nbr);
}

static int	base_index(char n, char *base)
{
	int		index;

	index = 0;
	while (base[index])
	{
		if (n == base[index] || ft_toupper(n) == base[index])
			return (index);
		index++;
	}
	return (0);
}

static int	get_base(char *base)
{
	int	index;
	int	index_2;
	int	base_n;

	if (base == NULL)
		return (0);
	base_n = ft_strlen(base);
	if (!base_n || base_n == 1)
		return (0);
	if (ft_strchr(base, '-') || ft_strchr(base, '+') || ft_strchr(base, ' '))
		return (-1);
	index = 0;
	while (base[index])
	{
		index_2 = 0;
		while (base[index_2])
		{
			if (base[index] == base[index_2] && index != index_2)
				return (0);
			index_2++;
		}
		index++;
	}
	return (base_n);
}

static int	power(int base, int n)
{
	if (!n)
		return (1);
	if (n == 1)
		return (base);
	return (base * power(base, n - 1));
}

static char	*input_check(char *str, char *base)
{
	int	sign;

	sign = 0;
	while ((*str) && (*str == '\n' || *str == '\t'
			|| *str == '\r' || *str == '\f'
			|| *str == '\v' || *str == 32))
		str++;
	if ((*str == '-' || *str == '+'))
	{
		sign = 1;
		str++;
	}
	if (ft_strchr(base, *str))
	{
		if (sign == 1)
			return (--str);
		return (str);
	}
	return ("0");
}
