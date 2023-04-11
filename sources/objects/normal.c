/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 15:23:10 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/11 00:43:12 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_v3d	normal_at(t_object obj, t_p3d _point)
{
	t_v3d	normal;

	_point = world_to_object(obj, _point);
	normal = obj.normal(obj, _point);
	normal = normal_to_world(obj, normal);
	return (normalize(normal));
}
