/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 17:03:00 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 19:26:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_base(char *base)
{
	int	counter;
	int	counter_2;

	counter = 0;
	while (base[counter])
	{
		counter_2 = 0;
		if (base[counter] == '+' || base[counter] == '-')
			return (0);
		while (base[counter_2])
		{
			if (base[counter] == base[counter_2] && counter != counter_2)
				return (0);
			counter_2++;
		}
		counter++;
	}
	return (counter);
}

void	ft_putnbr_base(unsigned int nbr, char *base, char **output)
{
	int							mod;
	unsigned int				quotient;
	int							base_num;

	base_num = check_base(base);
	if (base_num > 1)
	{
		quotient = nbr / base_num;
		mod = nbr % base_num;
		if (quotient != 0)
			ft_putnbr_base(quotient, base, output);
		if (*output == NULL)
		{
			(*output) = ft_calloc(2, sizeof(char));
			(*output)[0] = base[mod];
		}
		else
			(*output) = hex_concat(*output, base[mod]);
	}
}

char	*hex_concat(char *src, char c)
{
	size_t	len;
	char	*out;

	len = ft_strlen(src);
	out = ft_calloc(len + 2, sizeof(char));
	ft_memcpy(out, src, len);
	free(src);
	out[len] = c;
	return (out);
}

int	x_conv(va_list arg, t_flags flags)
{
	char	*output;
	int		l_out;
	int		nbr;

	output = NULL;
	nbr = va_arg(arg, int);
	ft_putnbr_base(nbr, HEXADECIMAL_L, &output);
	output = number_precision(flags, output);
	l_out = ft_strlen(output);
	if (flags.flags & zero && flags.flags & sharp && flags.width > l_out + 2)
		fill_zero_x(&output, flags.width);
	if (flags.flags & sharp && nbr != 0)
		fill_sharp(&output, 'x');
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}

int	xu_conv(va_list arg, t_flags flags)
{
	char	*output;
	int		l_out;
	int		nbr;

	output = NULL;
	nbr = va_arg(arg, int);
	ft_putnbr_base(nbr, HEXADECIMAL_U, &output);
	output = number_precision(flags, output);
	l_out = ft_strlen(output);
	if (flags.flags & zero && flags.flags & sharp && flags.width > l_out + 2)
		fill_zero_x(&output, flags.width);
	if (flags.flags & sharp && nbr != 0)
		fill_sharp(&output, 'X');
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}
