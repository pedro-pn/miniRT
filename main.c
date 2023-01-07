/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:24:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/06 18:59:09 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	initialize_minirt(void)
{
	start_mlx();
	img_init();
	
}

void	run(void)
{
	//mlx_demo();
	hello_world_img();
	clean_program();
}

int	main(int argc, char *argv[])
{
	t_file	file;
	
	(void)argc;
	
	initialize_minirt();
	run();
	// if (check_args(argc, argv))
	// 	exit(ERRARG);
//	file = check_file(argv[1]);
	
}