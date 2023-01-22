/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 10:43:23 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/20 12:43:32 by ppaulo-d         ###   ########.fr       */
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

static	t_c3d	get_diffuse_color(t_material m, t_lgt lgt)
{
	t_c3d	diffuse_color;

	diffuse_color =  scalar_times(lgt.light_dot_normal * m.diffuse,
			lgt.effective_color);
	return (diffuse_color);
}

static t_c3d	get_specular_color(t_material m, t_light light, t_lgt lgt)
{
	t_v3d	reflection;
	t_c3d	specular_color;
	double	reflect_dot_eye;
	double	factor;

	reflection = reflect(neg(lgt.lightv), lgt.params.normalv);
	reflect_dot_eye = dotp(reflection, lgt.params.eyev);
	if (reflect_dot_eye <= 0.0)
		specular_color = tcolor(0, 0, 0);
	else
	{
		factor = pow(reflect_dot_eye, m.shininess);
		specular_color = scalar_times(factor * m.specular, light.color);
	}
	return (specular_color);
}

static void	get_diff_spec_color(t_material m, t_light light, t_lgt *lgt)
{
	t_v3d	reflection;

	lgt->light_dot_normal = dotp(lgt->lightv, lgt->params.normalv);
	if (lgt->light_dot_normal < 0.0)
	{
		lgt->diffuse_color = tcolor(0, 0, 0);
		lgt->specular_color = tcolor(0, 0, 0);
	}
	else
	{
		lgt->diffuse_color = get_diffuse_color(m, *lgt);
		lgt->specular_color = get_specular_color(m, light, *lgt);
	}
}

t_c3d	lighting(t_material m, t_light light, t_lgt_param params)
{
	t_c3d	result;
	t_lgt	lgt;

	lgt.lightv = normalize(sub(light.position, params.position));
	lgt.effective_color = haddamard(m.color, light.color);
	lgt.params = params;
	lgt.ambient_color = scalar_times(m.ambient, lgt.effective_color);
	get_diff_spec_color(m, light, &lgt);
	result = add(lgt.ambient_color, lgt.diffuse_color);
	result = add(result, lgt.specular_color);
	result.w = 0;
	return (result);
}
