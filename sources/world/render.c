/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/17 14:01:21 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <pthread.h>

static pthread_mutex_t	*buffer_mutex(void)
{
	static pthread_mutex_t mutex;

	return (&mutex);
}

void	*render_threads(void *pixel)
{
	t_ray		_ray;
	t_rgb		color;
	int			x;
	int			y;

	x = *(int *)pixel;
	y = 0;
	while (y < camera()->vsize)
	{
		_ray = ray_for_pixel(x, y);
		color = tcolor_to_rgb(color_at(_ray, 4));
		pthread_mutex_lock(buffer_mutex());
		mlx_draw_pixel_rgb(image(), x, y, color);
		pthread_mutex_unlock(buffer_mutex());
		y++;
	}
	pthread_mutex_lock(buffer_mutex());
	print_progress();
	pthread_mutex_unlock(buffer_mutex());
	return (NULL);
}


void	render(void)
{
	int			x;
	int			*x_ptr;
	int			i;
	pthread_t	thread[camera()->hsize];

	x = 0;
	x_ptr = malloc(camera()->hsize * sizeof(int));
	pthread_mutex_init(buffer_mutex(), NULL);
	while (x < camera()->hsize)
	{
		x_ptr[x] = x;
		pthread_create(&thread[x], NULL, &render_threads, (void *)&x_ptr[x]);
		x++;
	}
	i = 0;
	while (i < camera()->hsize)
	{
		pthread_join(thread[i], NULL);
		i++;
	}
	pthread_mutex_destroy(buffer_mutex());
	free(x_ptr);
}
