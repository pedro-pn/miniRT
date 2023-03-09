/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/09 13:05:20 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"

double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

t_quad	quadratic(t_quad_param params)
{
	t_quad	quad;

	quad.det = discriminant(params.a, params.b, params.c);
	if (quad.det < 0)
		return (quad);
	quad.root_a = (-params.b + sqrt(quad.det)) / (2 * params.a);
	quad.root_b = (-params.b - sqrt(quad.det)) / (2 * params.a);
	return (quad);
}
