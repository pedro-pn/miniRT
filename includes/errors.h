/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 14:57:24 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/07/14 14:47:47 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define MLX_ERROR "Fail to initialize mlx"
# define GNL_ERROR "Fail to get line of required file"
# define ARGC_ERROR "Insufficient number of arguments"
# define FILE_ERR "Invalid scene file"
# define SCENE_EXT_ERROR "Invalid file extension"
# define OPEN_ERROR "Failed to open file"
# define CLOSE_ERROR "Failed to close file"
# define UNIMPLEMENTED_PARSER_ERR "Configuration not implemented"
# define MANY_AMBIENTS "Only 1 ambient light can be defined"
# define MANY_CAMERAS "Only 1 camera can be defined"
# define MANY_LIGHTS "Only 1 light can be defined"
# define NO_LIGHT "No light was defined"
# define NO_AMBIENT "No ambient light was defined"
# define NO_CAMERA "No camera was defined"

#endif /* DEFINES_H */
