/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/08 15:59:30 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "minirt.h"
# include "libft.h"
# define TRUE 1
# define FALSE 0

void	validate_scene(char *filename);
int	validate_line(char *line);
char	*jump_spaces(char *line);
int	ft_isfloat(char **nptr);
char	*jump_coordinate(char *line);
int	validate_camera(char *line);
int check_coordinate(char *line);
int	check_norm_coordinate(char *line);
int	validate_fov(char *line);
void	error_validate(char *line, int fd);
void	free_array(void **array);

#endif