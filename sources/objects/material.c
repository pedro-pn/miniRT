/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:05:24 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 13:47:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material(void)
{
	t_material	_material;

	_material.color = tcolor(1.0, 1.0, 1.0);
	_material.ambient = 0.1;
	_material.diffuse = 0.9;
	_material.specular = 0.9;
	_material.shininess = 200.0;
	return (_material);
}
