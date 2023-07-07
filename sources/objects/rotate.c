/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:19:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:20:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	fast_rotate_object(t_object *object, t_v3d new_normal)
{
	t_matrix	rotation_mx;
	t_matrix	rot_z;
	t_matrix	rot_y;
	double		alpha;
	double		beta;

	alpha = atan2(
			sqrt(new_normal.x * new_normal.x + new_normal.z * new_normal.z),
			new_normal.y);
	beta = atan2(new_normal.z, new_normal.x);
	rotation_z(-alpha, &rot_z);
	rotation_y(-beta, &rot_y);
	mx_product(rot_y, rot_z, &rotation_mx);
	multiply_transform(object, rotation_mx);
}
