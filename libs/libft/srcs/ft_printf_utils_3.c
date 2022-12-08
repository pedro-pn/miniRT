/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_3_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 18:35:04 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 23:17:39 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	width_conv(t_flags flags, int l_out)
{
	int	counter;

	counter = 0;
	while (counter < flags.width - l_out && flags.width > l_out)
	{
		if (flags.flags & zero)
			ft_putchar_fd('0', 1);
		else
			ft_putchar_fd(' ', 1);
		counter++;
	}
	return (counter);
}

int	width_get(char ***inputs)
{
	int		width;
	int		index;
	int		start;
	char	*nbr;

	index = 0;
	start = -1;
	width = 0;
	while ((**inputs)[index])
	{
		if (ft_strchr(DECIMAL, (**inputs)[index]) && start == -1)
			start = index;
		if ((!ft_isdigit((**inputs)[index + 1])) && start != -1)
		{
			nbr = ft_substr(**inputs, start, index - start + 1);
			width = ft_atoi(nbr);
			free(nbr);
			break ;
		}
		if ((**inputs)[index] == '.')
			break ;
		index++;
	}
	return (width);
}

int	check_zero(char ***inputs)
{
	int	index;

	index = 0;
	while ((**inputs)[index])
	{
		if (ft_strchr(DECIMAL, (**inputs)[index]))
			break ;
		if ((**inputs)[index] == '0')
			return (1);
		index++;
	}
	return (0);
}

int	check_precision(char ***inputs)
{
	int		index;
	int		start;
	int		width;
	char	*nbr;

	index = 0;
	start = -1;
	width = 0;
	nbr = ft_strchr(**inputs, '.');
	if (!nbr)
		return (-1);
	while ((nbr)[index])
	{
		if (ft_isdigit(nbr[index]) && start == -1)
			start = index;
		if ((!ft_isdigit(nbr[index + 1])) && start != -1)
		{
			nbr = ft_substr(nbr, start, index - start + 1);
			width = ft_atoi(nbr);
			free(nbr);
			break ;
		}
		index++;
	}
	return (width);
}

char	*number_precision(t_flags flags, char *output)
{
	char	*s_zero;
	int		l_out;
	char	*temp;

	l_out = ft_strlen(output);
	if (l_out == 1 && output[0] == '0' && (flags.precision == 0))
		output[0] = 0;
	if (output[0] == '-' || output[0] == '+')
		l_out--;
	if ((int) l_out < flags.precision)
	{
		s_zero = ft_calloc(flags.precision - l_out + 1, sizeof(char));
		ft_memset(s_zero, '0', flags.precision - l_out);
		if (output[0] == '-' || output[0] == '+')
		{
			s_zero[0] = output[0];
			output[0] = '0';
		}
		temp = ft_strdup(output);
		free(output);
		output = ft_strjoin(s_zero, temp);
		free(temp);
		free(s_zero);
	}
	return (output);
}
