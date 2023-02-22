/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/22 13:50:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <pthread.h>

static pthread_mutex_t	*buffer_mutex(void)
{
	static pthread_mutex_t mutex;

	return (&mutex);
}

static pthread_mutex_t	*task_mutex(void)
{
	static pthread_mutex_t mutex;

	return (&mutex);
}

static int	*task_count(void)
{
	static int	task_count = 0;
	
	return (&task_count);
}

void	render_task(t_task task)
{
	t_ray		_ray;
	t_rgb		color;

	_ray = ray_for_pixel(task.x, task.y);
	color = tcolor_to_rgb(color_at(_ray, 4));
	pthread_mutex_lock(buffer_mutex());
	mlx_draw_pixel_rgb(image(), task.x, task.y, color);
	print_progress();
	pthread_mutex_unlock(buffer_mutex());
	
}

void	*execute_task(void *args)
{
	t_task	task;
	t_task	*tasks;
	int		i;

	tasks = (t_task *)args;
	while (1)
	{
		pthread_mutex_lock(task_mutex());
		if (*task_count() == 0)
		{
			pthread_mutex_unlock(task_mutex());
			return (NULL);
		}
		task = tasks[0];
		i = 0;
		while (i < *task_count() - 1)
		{
			tasks[i] = tasks[i + 1];
			i++;
		}
		*task_count() -= 1;
		pthread_mutex_unlock(task_mutex());
		render_task(task);

	}
}

void	start_threads(t_task *tasks)
{
	pthread_t	*th;
	int			i;
	
	th = malloc(10 * sizeof(*th));
	pthread_mutex_init(task_mutex(), NULL);
	pthread_mutex_init(buffer_mutex(), NULL);
	i = 0;
	while (i < 10)
	{
		pthread_create(&th[i], NULL, &execute_task, tasks);
		i++;
	}
	i = 0;
	while(i < 10)
	{
		pthread_join(th[i], NULL);
		i++;
	}
	pthread_mutex_destroy(task_mutex());
	pthread_mutex_destroy(buffer_mutex());
}

void	render(void)
{
	t_task	*tasks;
	int		n_task;
	int		x;
	int		y;
	int		i = 0;

	n_task = camera()->hsize * camera()->vsize;
	tasks = malloc(n_task * sizeof(tasks));
	x = 0;
	while (x < camera()->hsize)
	{
		y = 0;
		while (y < camera()->vsize)
		{
			tasks[i] = (t_task){x, y};
			*task_count() += 1;
			y++;
			i++;
		}
		x++;
	}
	start_threads(tasks);
}
