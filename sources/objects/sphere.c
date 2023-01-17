/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 20:11:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/17 14:53:33 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static	t_ray	ray_transf_inverse(t_matrix _transform, t_ray _ray)
{
	t_matrix	mx_inv;

	mx_inverse(_transform, &mx_inv);
	return (transform(mx_inv, _ray));
}

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

t_intx	*new_intersection(double t, t_object *obj)
{
	t_intx	*inter;

	inter = ft_calloc(1, sizeof(*inter));
	inter->object = obj;
	inter->t = t;
	return (inter);
}

void	create_intersection(t_list **list, double t, t_object *obj)
{
	t_intx	*inter;

	inter = new_intersection(t, obj);
	ft_lstadd_back(list, ft_lstnew(inter));
}

t_intxs	intersect(t_object *obj, t_ray _ray)
{
	t_quad_param	params;
	t_intxs			intxs;
	t_quad			quad;

	params = sphere_params(obj, _ray);
	quad = quadratic(params.a, params.b, params.c);
	if (quad.det < 0)
	{
		intxs.count = 0;
		intxs.intersections = NULL;
		return (intxs);
	}
	intxs.count = 2;
	intxs.intersections = NULL;
	create_intersection(&intxs.intersections, quad.root_b, obj);
	create_intersection(&intxs.intersections, quad.root_a, obj);
	return (intxs);
}

/* Creates a standard sphere for test purpose*/
t_object	*sphere(void)
{
	static int	count;
	t_object	*_sphere;

	count++;
	_sphere = ft_calloc(1, sizeof(*_sphere));
	_sphere->type = SPHERE;
	_sphere->id = count;
	_sphere->origin = point(0, 0, 0);
	_sphere->radius = 1.0;
	_sphere->color = color_rgb(255, 0, 0);
	mx_identity(&_sphere->transform);
	return (_sphere);
}
