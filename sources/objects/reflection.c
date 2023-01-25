/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:56:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:43:27 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	reflect(t_v3d in, t_v3d normal)
{
	t_v3d	result;

	result = scalar_times(2 * dotp(in, normal), normal);
	return (sub(in, result));
}
