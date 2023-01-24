/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 19:07:31 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/24 14:45:48 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// static void	handle_arg_error(int argc);
// static void	handle_invalid_format(void);
// static void	check_file(char *filename);

// int	check_args(int argc, char **argv)
// {
// 	char	*format;

// 	if (argc != 2)
// 		handle_arg_error(argc);
// 	format = ft_strrchr(argv[1], '.');
// 	if (!format)
// 		handle_invalid_format();
// 	if (ft_strcmp(format, ".rt"))
// 		handle_invalid_format();
// 	check_file(argv[1]);
// }

// static void	handle_arg_error(int argc)
// {
// 	if (argc == 1)
// 		ft_putendl_fd("Insert a scene format (.rt) file", 2);
// 	else if (argc > 2)
// 		ft_putendl_fd("Error\nminiRT: too many arguments!", 2);
// 	exit(ERRARG);
// }

// static void	handle_invalid_format(void)
// {
// 	ft_putendl_fd("Error\nminiRT: invalid format!\nExpected .rt format file.",
// 		2);
// 	exit(ERRFMT);
// }

// static void	check_file(char *filename)
// {
// 	int	fd;

// 	fd = open(filename, O_RDONLY);
// 	if (fd < 0)
// 	{
// 		ft_putstr_fd("Error\nCannot open \"", 2);
// 		ft_putstr_fd(filename, 2);
// 		ft_putendl_fd("\"", 2);
// 		exit(ERRFILE);
// 	}
// 	close(fd);
// }
