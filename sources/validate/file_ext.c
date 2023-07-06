/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_ext.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 16:41:06 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/06 16:46:45 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	check_scene_ext(void)
{
	char	*extension;

	extension = ft_strrchr(scene(), '.');
	if (extension == NULL)
		die(FILE_ERR);
	if (ft_strcmp(extension, ".rt"))
		die(SCENE_EXT_ERROR);
}
