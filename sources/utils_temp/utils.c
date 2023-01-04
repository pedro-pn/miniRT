/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 14:47:57 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/04 15:39:17 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	tuple_inspect(t_t3d tuple)
{
	ft_putstr_fd("Inspect tuple\n tuple: (", 1);
	ft_putdouble_fd(tuple.x, 1, 4);
	ft_putstr_fd(", ", 1);
	ft_putdouble_fd(tuple.y, 1, 4);
	ft_putstr_fd(", ", 1);
	ft_putdouble_fd(tuple.z, 1, 4);
	ft_putstr_fd(", ", 1);
	ft_putdouble_fd(tuple.w, 1, 4);
	ft_putendl_fd(")", 1);
}
