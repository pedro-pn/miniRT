/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/14 14:32:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/14 14:47:36 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_bool	check_scene_status(void)
{
	if (ambient_count(false) > 1)
	{
		*val_error() = MANY_AMBIENTS;
		return (false);
	}
	if (camera_count(false) > 1)
	{
		*val_error() = MANY_CAMERAS;
		return (false);
	}
	if (light_count(false) > 1)
	{
		*val_error() = MANY_LIGHTS;
		return (false);
	}
	return (true);
}

void	check_scene_validation(void)
{
	if (ambient_count(false) == 0)
		die(NO_AMBIENT);
	if (camera_count(false) == 0)
		die(NO_CAMERA);
	if (light_count(false) == 0)
		die(NO_LIGHT);
}
