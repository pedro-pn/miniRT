/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_handle.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 11:15:17 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 11:23:04 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	safe_open(char const *file_path)
{
	int	fd;

	fd = open(file_path, O_RDONLY);
	if (fd < 0)
	{
		ft_putstr_fd("couldn't open ", 2);
		ft_putendl_fd(file_path, 2);
		die(OPEN_ERROR);
	}
	return (fd);
}

void	safe_close(int fd)
{
	int status;

	status = close(fd);
	if (status < 0)
		die (CLOSE_ERROR);
}
