/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 15:30:51 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/22 15:54:22 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	*execute_task(void *args)
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

static void	create_threads(pthread_t *threads, t_task *tasks)
{
	int	i;

	i = 0;
	while (i < THREAD_NUM)
	{
		pthread_create(&threads[i], NULL, &execute_task, tasks);
		i++;
	}
	i = 0;
}

static void	join_threads(pthread_t *threads)
{
	int	i;

	i = 0;
	while(i < THREAD_NUM)
	{
		pthread_join(threads[i], NULL);
		i++;
	}
}

void	start_threads(t_task *tasks)
{
	pthread_t	*threads;

	threads = malloc(THREAD_NUM * sizeof(*threads));
	pthread_mutex_init(task_mutex(), NULL);
	pthread_mutex_init(buffer_mutex(), NULL);
	create_threads(threads, tasks);
	join_threads(threads);
	pthread_mutex_destroy(task_mutex());
	pthread_mutex_destroy(buffer_mutex());
	free(threads);
}
