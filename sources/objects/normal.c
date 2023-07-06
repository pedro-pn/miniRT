/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:10 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 20:50:18 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	normal_at(t_object obj, t_p3d _point, t_intx inter)
{
	t_v3d	normal;

	_point = world_to_object(obj, _point);
	normal = obj.normal(obj, _point, inter);
	normal = normal_to_world(obj, normal);
	return (normalize(normal));
}
