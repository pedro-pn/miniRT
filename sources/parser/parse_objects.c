/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 12:00:21 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/11 09:48:26 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	parse_sphere(char *line)
{
	t_p3d		origin;
	double		diameter;
	t_rgb		color;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	diameter = ft_atof(line);
	line = skip_field(line);
	color = parse_color(line);
	create_sphere(origin, diameter, color);
}

void	parse_plane(char *line)
{
	t_p3d		origin;
	t_v3d		normal;
	t_rgb		color;

	line = skip_field(line);
	origin = parse_point(line);
	line = skip_field(line);
	normal = parse_vector(line);
	line = skip_field(line);
	color = parse_color(line);
	create_plane(origin, normal, color);
}

void	parse_cylinder(char *line)
{
	t_create_cylinder	p;

	line = skip_field(line);
	p.origin = parse_point(line);
	line = skip_field(line);
	p.normal = parse_vector(line);
	line = skip_field(line);
	p.diameter = ft_atof(line);
	line = skip_field(line);
	p.height = ft_atof(line);
	line = skip_field(line);
	p.color = parse_color(line);
	create_cylinder(p);
}

void	parse_cube(char *line)
{
	t_create_cube	p;

	line = skip_field(line);
	p.origin = parse_point(line);
	line = skip_field(line);
	p.normal = parse_vector(line);
	line = skip_field(line);
	p.width = ft_atof(line);
	line = skip_field(line);
	p.height = ft_atof(line);
	line = skip_field(line);
	p.length = ft_atof(line);
	line = skip_field(line);
	p.color = parse_color(line);
	create_cube(p);
}
