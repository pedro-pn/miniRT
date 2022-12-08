/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_1_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 16:37:05 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 18:02:45 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	c_conv(va_list arg, t_flags flags)
{
	unsigned char	c;
	int				l_out;

	c = (unsigned char) va_arg(arg, int);
	l_out = 1;
	if (flags.flags & minus)
	{
		ft_putchar_fd(c, 1);
		l_out += width_conv(flags, l_out);
	}
	else
	{
		l_out += width_conv(flags, l_out);
		ft_putchar_fd(c, 1);
	}
	return (l_out);
}

int	s_conv(va_list arg, t_flags flags)
{
	char	*str;
	char	*output;
	int		l_out;

	output = NULL;
	str = va_arg(arg, char *);
	if ((!(flags.flags & dot) || flags.precision >= 6) && !str)
		output = ft_strdup("(null)");
	else if (!str)
		str = "";
	if (!output)
		output = ft_strdup(str);
	if ((int) ft_strlen(output) > flags.precision && flags.flags & dot)
	{
		free(output);
		output = ft_substr(str, 0, flags.precision);
	}
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}

int	p_conv(va_list arg, t_flags flags)
{
	unsigned long int	n;
	char				*output;
	int					l_out;

	n = (unsigned long int) va_arg(arg, void *);
	if (!n)
		output = ft_strdup("(nil)");
	else
	{
		output = ft_calloc(3, sizeof(char));
		output[0] = '0';
		output[1] = 'x';
		ft_putnbr_base_l(n, HEXADECIMAL_L, &output);
	}
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}

int	id_conv(va_list arg, t_flags flags)
{
	char	*output;
	int		l_out;
	int		nbr;

	nbr = va_arg(arg, int);
	output = ft_itoa(nbr);
	l_out = ft_strlen(output);
	if (flags.flags & plus && nbr >= 0)
		fill_plus(&output);
	if (flags.flags & zero && output[0] == '-' && flags.width > l_out)
		fill_zero(&output, flags.width, '-');
	if (flags.flags & zero && output[0] == '+' && flags.width > l_out)
		fill_zero(&output, flags.width, '+');
	output = number_precision(flags, output);
	if (flags.flags & space && nbr >= 0)
		fill_space(&output);
	if (flags.flags & zero && output[0] == ' ' && flags.width > l_out)
		fill_zero(&output, flags.width, ' ');
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}

int	u_conv(va_list arg, t_flags flags)
{
	char	*output;
	int		l_out;

	output = ft_utoa(va_arg(arg, unsigned int));
	output = number_precision(flags, output);
	l_out = pad_output(flags, output);
	free(output);
	return (l_out);
}
