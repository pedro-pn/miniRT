/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 16:20:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 18:27:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	perc_conv(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}

int	output(const char *format, int start, int end)
{
	char	*s;
	int		l_out;

	s = ft_substr(format, start, end - start);
	l_out = ft_strlen(s);
	ft_putstr_fd(s, 1);
	free(s);
	return (l_out);
}

int	pad_output(t_flags flags, char *output)
{
	int	l_out;

	l_out = ft_strlen(output);
	if (flags.flags & minus)
	{
		ft_putstr_fd(output, 1);
		l_out += width_conv(flags, l_out);
	}
	else
	{
		l_out += width_conv(flags, l_out);
		ft_putstr_fd(output, 1);
	}
	return (l_out);
}

void	ft_putnbr_base_l(unsigned long int nbr, char *base, char **output)
{
	int							mod;
	unsigned long int			quotient;
	int							base_num;

	base_num = check_base(base);
	if (base_num > 1)
	{
		quotient = nbr / base_num;
		mod = nbr % base_num;
		if (quotient != 0)
			ft_putnbr_base_l(quotient, base, output);
		if (*output == NULL)
		{
			(*output) = ft_calloc(2, sizeof(char));
			(*output)[0] = base[mod];
		}
		else
			(*output) = hex_concat(*output, base[mod]);
	}
}

void	get_flags(char ***inputs, t_flags *flags)
{
	flags->flags = 0;
	flags->precision = check_precision(inputs);
	flags->width = width_get(inputs);
	if (ft_strchr(**inputs, '-'))
		flags->flags += minus;
	if (flags->precision != -1)
		flags->flags += dot;
	if (ft_strchr(**inputs, '+'))
		flags->flags += plus;
	if (ft_strchr(**inputs, '#'))
		flags->flags += sharp;
	if (ft_strchr(**inputs, ' ') && !(flags->flags & plus))
		flags->flags += space;
	if (check_zero(inputs) && !(flags->flags & dot)
		&& !(flags->flags & minus))
		flags->flags += zero;
}
