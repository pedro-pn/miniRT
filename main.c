/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro <pedro@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 18:24:18 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/04/11 21:21:49 by pedro            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"


void	initialize_minirt(void)
{
	start_mlx();
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
	// hexagon_demo();
}

int	main(int argc, char *argv[])
{
	(void)argc;
	(void)argv;
	
	initialize_minirt();
	run();
	clean_program();
	// if (check_args(argc, argv))
	// 	exit(ERRARG);
//	file = check_file(argv[1]);
	return (0);
}
