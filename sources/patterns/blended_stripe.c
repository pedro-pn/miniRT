/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   blended_stripe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/01 12:15:47 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/01 12:15:52 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_patt	blended_strp_pattern(t_c3d color_a, t_c3d color_b)
{
	t_patt	patt;

	patt = pattern(color_a, color_b);
	patt.patt_at = blended_strp_at;
	return (patt);
}

t_c3d	blended_strp_at(t_patt patt, t_p3d point)
{
	t_matrix	rot_1;
	t_matrix	rot_2;
	t_c3d		result_1;
	t_c3d		result_2;

	rotation_y(MY_PI / 4, &rot_1);
	rotation_y(-MY_PI / 4, &rot_2);
	result_1 = stripe_at(patt, mx_tuple_product(rot_1, point));
	result_2 = stripe_at(patt, mx_tuple_product(rot_2, point));
	return (color_avarage(result_1, result_2));
}
