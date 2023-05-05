/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bbox_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 14:17:37 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/05/05 14:21:24 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	box_contains_box(t_box b1, t_box b2)
{
	if (box_contains_point(b1, b2.max) && box_contains_point(b1, b2.min))
		return (true);
	return (false);
}
