/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 14:28:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/17 14:29:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	transform(t_matrix mx, t_ray _ray)
{
	_ray.origin = mx_tuple_product(mx, _ray.origin);
	_ray.direction = mx_tuple_product(mx, _ray.direction);
	return (_ray);
}
