/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   die.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:28:52 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 14:59:05 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	print_error(char *error_message)
{
	ft_putstr_fd("minirt: ", 2);
	ft_putendl_fd(error_message, 2);
}

void	die(char *error_message)
{
	print_error(error_message);
	clean_program();
	exit(EXIT_FAILURE);
}
