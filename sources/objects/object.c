/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:44:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 20:47:37 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	object_count(void)
{
	static int	id = 0;

	id++;
	return (id);
}

void	create_object(t_object *object)
{
	object->id = object_count();
	ft_lstadd_back(&world()->objects, ft_lstnew(object));
}
