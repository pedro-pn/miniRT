/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/12/12 13:00:30 by ppaulo-d         ###   ########.fr       */
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
char	*jump_info(char *line);
int	validate_camera(char *line);
int check_coordinate(char *line);
int	check_norm_coordinate(char *line);
int	validate_fov(char *line);
void	error_validate(char *line, int fd);
void	free_array(void **array);
int	validate_ambient(char *line);
int	check_color(char *line);
int	is_rgb(char *line);


#endif