/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:27:24 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/22 15:28:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

pthread_mutex_t	*buffer_mutex(void)
{
	static pthread_mutex_t mutex;

	return (&mutex);
}

pthread_mutex_t	*task_mutex(void)
{
	static pthread_mutex_t mutex;

	return (&mutex);
}

int	*task_count(void)
{
	static int	task_count = 0;
	
	return (&task_count);
}
