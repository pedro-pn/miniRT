/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_box.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 16:32:22 by pedro             #+#    #+#             */
/*   Updated: 2023/07/12 19:45:13 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_box	sphere_bounding_box(t_object sphere)
{
	t_box	box;

	(void)sphere;
	box.min = point(-sphere.radius, -sphere.radius, -sphere.radius);
	box.max = point(sphere.radius, sphere.radius, sphere.radius);
	return (box);
}
