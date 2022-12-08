/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_4_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d < ppaulo-d@student.42sp.org.br    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 00:09:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/05/27 23:11:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	fill_zero(char **output, int width, char sign)
{
	char	*zero;
	int		l_out;
	char	*temp;

	l_out = ft_strlen(*output);
	(*output)[0] = '0';
	zero = ft_calloc(width - l_out + 1, sizeof(char));
	ft_memset(zero, '0', width - l_out);
	zero[0] = sign;
	temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(zero, temp);
	free(temp);
	free(zero);
}

void	fill_sharp(char **output, char x)
{
	char	*zerox;
	char	*temp;

	zerox = ft_calloc(3, sizeof(char));
	zerox[0] = '0';
	zerox[1] = x;
	temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(zerox, temp);
	free(temp);
	free(zerox);
}

void	fill_space(char **output)
{
	char	*space;
	char	*temp;

	space = ft_calloc(2, sizeof(char));
	space[0] = ' ';
	temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(space, temp);
	free(temp);
	free(space);
}

void	fill_plus(char **output)
{
	char	*plus;
	char	*temp;

	plus = ft_calloc(2, sizeof(char));
	plus[0] = '+';
	temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(plus, temp);
	free(plus);
	free(temp);
}

void	fill_zero_x(char **output, int width)
{
	char	*s_zero;
	int		l_out;
	char	*temp;

	l_out = ft_strlen(*output) + 2;
	s_zero = ft_calloc(width - l_out + 1, sizeof(char));
	ft_memset(s_zero, '0', width - l_out);
	temp = ft_strdup(*output);
	free(*output);
	*output = ft_strjoin(s_zero, temp);
	free(temp);
	free(s_zero);
}
