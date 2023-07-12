/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 12:38:45 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/12 20:00:07 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_input_data	*input_data(void)
{
	return (&data()->input);
}

t_group	*rt_objects(void)
{
	return (data()->input.rt_objects);
}
