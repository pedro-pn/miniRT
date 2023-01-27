/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 21:44:26 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/26 13:53:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int object_count(void)
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
