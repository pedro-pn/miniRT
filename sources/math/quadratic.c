/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quadratic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:45:19 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/25 13:43:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_math.h"

double	discriminant(double a, double b, double c)
{
	return (b * b - 4 * a * c);
}

t_quad	quadratic(double a, double b, double c)
{
	t_quad	quad;

	quad.det = discriminant(a, b, c);
	if (quad.det < 0)
		return (quad);
	quad.root_a = (-b + sqrt(quad.det)) / (2 * a);
	quad.root_b = (-b - sqrt(quad.det)) / (2 * a);
	return (quad);
}
