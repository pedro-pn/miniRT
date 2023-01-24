/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transformation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:28:34 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 19:42:08 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	view_transformation(t_view view, t_matrix *result)
{
	t_v3d		forward;
	t_v3d		left;
	t_v3d		true_up;
	t_v3d		normal_up;
	t_matrix	mx_trans;
	t_matrix	orientation;

	forward = normalize(sub(view.to, view.from));
	normal_up = normalize(view.up);
	left = cross(forward, normal_up);
	true_up = cross(left, forward);
	set_matrix(&orientation, (t_set_matrix){
		left.x, left.y, left.z, 0,
		true_up.x, true_up.y, true_up.z, 0,
		-forward.x, -forward.y, -forward.z, 0,
		0, 0, 0, 1
	});
	translation(vector(-view.from.x, -view.from.y, -view.from.z), &mx_trans);
	mx_product(orientation, mx_trans, result);
}
