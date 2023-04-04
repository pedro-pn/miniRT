/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:24:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/04 00:15:00 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	initialize_minirt(void)
{
	start_mlx();
	start_buffer();
	// img_init();
	
}

void	run(void)
{
	//mlx_demo();
	//hello_world_img();
	//projectile_demo();
	//clock_demo();
	///sphere_demo();
	// sphere_3d_demo();
	//world_demo();
	// world_demo_v2();
	world_demo_v3();
	// book_cover();
	clean_program();
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	
	initialize_minirt();
	run();
	// if (check_args(argc, argv))
	// 	exit(ERRARG);
//	file = check_file(argv[1]);
}