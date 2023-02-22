/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 23:41:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/02/22 15:54:12 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	render_task(t_task task)
{
	t_ray		_ray;
	t_rgb		color;

	_ray = ray_for_pixel(task.x, task.y);
	color = tcolor_to_rgb(color_at(_ray, ITER_MAX));
	pthread_mutex_lock(buffer_mutex());
	mlx_draw_pixel_rgb(image(), task.x, task.y, color);
	print_progress();
	pthread_mutex_unlock(buffer_mutex());
}

void	render(void)
{
	t_task	*tasks;
	int		n_task;
	int		x;
	int		y;
	int		i;

	n_task = camera()->hsize * camera()->vsize;
	tasks = malloc(n_task * sizeof(tasks));
	x = 0;
	i = 0;
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
	free(tasks);
}
