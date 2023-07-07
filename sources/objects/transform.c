/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:13:49 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/07 12:33:01 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	multiply_transform(t_object *object, t_matrix mx)
{
	t_matrix	result;

	mx_product(object->transform, mx, &result);
	mx_copy(result, &(object->transform));
}

void	translate_object(t_object *object, t_p3d new_origin)
{
	t_matrix	translation_mx;

	translation(vector(new_origin.x, new_origin.y, new_origin.z),
		&translation_mx);
	multiply_transform(object, translation_mx);
}

void	scale_object(t_object *object, t_v3d new_scale)
{
	t_matrix	scale_mx;

	scaling(new_scale, &scale_mx);
	multiply_transform(object, scale_mx);
}
