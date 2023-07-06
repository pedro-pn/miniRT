/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:30:22 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 16:32:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	argc(void)
{
	return (data()->argc);
}

void	set_argc(int argc)
{
	data()->argc = argc;
}

char	**argv(void)
{
	return (data()->argv);
}

void	set_argv(char **argv)
{
	data()->argv = argv;
}
