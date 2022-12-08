/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:23:14 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/07 18:14:15 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "libft.h"
# include <fcntl.h>
# include "mlx.h"

# define ERRARG 1
# define ERRFMT 2
# define ERRFILE 3
# define SPACES " \t"

typedef struct s_file
{
	t_list	*ambient;
	t_list	*camera;
	t_list	*light;
	t_list	*sphere;
	t_list	*plane;
	t_list	*cylinder;
	
}			t_file;

typedef struct s_scene_val
{
	int	camera;
	int	ambient;
	int	light;
}			t_scene_val;

/* args.c file */

int		check_args(int argc, char **argv);
void	file_init(t_file *file);

#endif