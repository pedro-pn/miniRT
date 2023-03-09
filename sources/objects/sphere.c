/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:11:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/03/09 13:05:42 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_quad_param	sphere_params(t_object *obj, t_ray _ray)
{
	t_quad_param	params;
	t_v3d			sphere_to_ray;

	_ray = ray_transf_inverse(obj->transform, _ray);
	sphere_to_ray = sub(_ray.origin, obj->origin);
	params.a = dotp(_ray.direction, _ray.direction);
	params.b = 2 * dotp(_ray.direction, sphere_to_ray);
	params.c = dotp(sphere_to_ray, sphere_to_ray) - obj->radius * obj->radius;
	return (params);
}

t_intxs	intersect_sphere(t_object *obj, t_ray _ray)
{
	t_quad_param	params;
	t_intxs			intxs;
	t_quad			quad;

	params = sphere_params(obj, _ray);
	quad = quadratic(params);
	if (quad.det < 0)
		return (empty_intersection());
	intxs.count = 2;
	intxs.intersections = NULL;
	create_intersection(&intxs.intersections, quad.root_b, obj);
	create_intersection(&intxs.intersections, quad.root_a, obj);
	return (intxs);
}

t_v3d	sphere_normal_at(t_object obj, t_p3d point)
{
	return (sub(point, obj.origin));
}

/* Creates a standard sphere for test purpose*/
t_object	*sphere(void)
{
	t_object	*_sphere;

	_sphere = ft_calloc(1, sizeof(*_sphere));
	_sphere->type = SPHERE;
	_sphere->origin = point(0, 0, 0);
	_sphere->radius = 1.0;
	_sphere->color = color_rgb(255, 0, 0);
	_sphere->material = material();
	_sphere->intersect = intersect_sphere;
	_sphere->normal = sphere_normal_at;
	mx_identity(&_sphere->transform);
	return (_sphere);
}

t_object	*glass_sphere(void)
{
	t_object	*s;

	s = ft_calloc(1, sizeof(*s));
	s->origin = point(0, 0, 0);
	s->radius = 1.0;
	mx_identity(&s->transform);
	s->material = material();
	s->material.transparency = 1.0;
	s->material.refractive_index = 1.5;
	s->normal = sphere_normal_at;
	s->intersect = intersect_sphere;
	return (s);
}
