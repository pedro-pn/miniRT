/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/06/20 00:58:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

/* PARSER */

// .rt files

void	validate_scene(char *filename);
int		validate_line(char *line);
int		validate_camera(char *line);
int		check_coordinate(char *line);
int		check_norm_coordinate(char *line);
int		validate_fov(char *line);
void	error_validate(char *line, int fd);
int		validate_ambient(char *line);
int		check_color(char *line);
int		check_amb_light(char *line);
int		validate_light(char *line);
int		validate_sphere(char *line);
int		validate_plane(char *line);
int		validate_cylinder(char *line);

// .obj files

/* PARSER */

typedef struct s_parser
{
	t_p3d	*vertices;
	size_t	count;
	t_list	*faces;
}			t_parser;

typedef	struct s_face
{
	int		*faces;
	size_t	id;
	size_t	size;
}			t_face;

t_parser		parser_obj_file(int file);

t_bool			parse_faces(t_parser *parser, char *line);
t_bool			parse_group(char *line);

t_group			*default_group(t_parser parser);
t_group			*obj_to_group(t_parser parser);

void			clean_faces(void *face);
int				obj_group_id(t_bool increment);

// utils

char			*jump_spaces(char *line);
char			*jump_info(char *line);
char			*get_next_info(char *line);
int				ft_isfloat(char **nptr);
int				is_rgb(char *line);

#endif
