/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/19 16:08:11 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	point_light(t_p3d position, t_c3d color)
{
	t_light	*_light;

	_light = light();
	_light->position = position;
	_light->color = color;
}

t_c3d	lightning(t_material m, t_light light, t_p3d position, t_v3d eyev, t_v3d normalv)
{
	t_c3d	effective_color;
	t_v3d	lightv;
	t_v3d	reflection;
	double	light_dot_normal;
	double	reflect_dot_eye;
	double	factor;
	t_c3d	diffuse_color;
	t_c3d	specular_color;
	t_c3d	ambient_color;
	t_c3d	result;


	effective_color = haddamard(m.color, light.color);
	lightv = normalize(sub(light.position, position));
	ambient_color = scalar_times(m.ambient, effective_color);
	light_dot_normal = dotp(lightv, normalv);
	if (light_dot_normal < 0)
	{
		diffuse_color = tcolor(0, 0, 0);
		specular_color = tcolor(0, 0, 0);
	}
	else
		diffuse_color =  scalar_times(light_dot_normal * m.diffuse, effective_color);
	reflection = reflect(neg(lightv), normalv);
	reflect_dot_eye = dotp(reflection, eyev);
	if (reflect_dot_eye < 0)
		specular_color = tcolor(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, m.shininess);
		specular_color = scalar_times(factor * m.specular, light.color);
	}
	result = add(ambient_color, diffuse_color);
	result = add(result, specular_color);
	return (result);
}
