/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:55:54 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/12 11:44:02 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"

/* VALIDATE */

// .rt files

void			validate_scene(void);
void			error_validate(char *line, int fd);
t_bool			validate_line(char *line);
t_bool			validate_camera(char *line);
t_bool			check_coordinate(char *line);
t_bool			check_norm_coordinate(char *line);
t_bool			validate_fov(char *line);
t_bool			validate_ambient(char *line);
t_bool			check_color(char *line);
t_bool			check_amb_light(char *line);
t_bool			validate_light(char *line);
t_bool			validate_sphere(char *line);
t_bool			validate_plane(char *line);
t_bool			validate_cylinder(char *line);
t_bool			validate_cube(char *line);
t_bool			validate_cone(char *line);


/* PARSER */

// .obj (wavefront) files

typedef struct s_parser
{
	t_p3d	*vertices;
	t_v3d	*normals;
	size_t	vtx_count;
	size_t	n_count;
	t_list	*faces;
}			t_parser;

typedef	struct s_face
{
	int		*vtx_indexes;
	int		*n_indexes;
	size_t	vtx_indexes_size;
	size_t	n_indexes_size;
	size_t	id;
}			t_face;

t_parser		parser_obj_file(int file);

t_bool			parse_vertices(t_parser *parser, char *line);
t_bool			parse_normals(t_parser *parser, char *line);
t_bool			parse_faces(t_parser *parser, char *line);
t_bool			parse_group(char *line);
t_bool			parse_face_normal(t_face *face, char **line, size_t n_count);

t_group			*default_group(t_parser parser);
t_group			*obj_to_group(t_parser parser);

void			clean_parser(t_parser *parser);
void			clean_faces(void *face);
int				obj_group_id(t_bool increment);

// .rt files

void			parse_scene(void);
t_rgb			parse_color(char *line);
t_v3d			parse_vector(char *line);
t_p3d			parse_point(char *line);

void			parse_ambient_light(char *line);
void			parse_camera(char *line);
void			parse_light(char *line);

void			parse_sphere(char *line);
void			parse_cylinder(char *line);
void			parse_plane(char *line);
void			parse_cube(char *line);
void			parse_cone(char *line);

// utils

char			*skip_field(char *line);
char			*jump_spaces(char *line);
char			*jump_info(char *line);
char			*get_next_info(char *line);
t_bool			is_rgb(char *line);
t_bool			isfloat(char **nptr);

#endif
