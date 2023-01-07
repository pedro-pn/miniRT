/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_to_ppm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 15:04:55 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/06 19:09:35 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_mlx.h"
#include <stdio.h>

void	save_ppm_file(char *buffer, char *filename)
{
	int	fd;

	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0664);
	ft_putstr_fd(buffer, fd);
	close(fd);
}

char	*make_ppm_header(t_mlx_img *img, char *cursor)
{
	char	*_width;
	char	*_height;

	_width = ft_itoa(img->_width);
	_height = ft_itoa(img->_height);
	cursor = ft_strcpy_end(cursor, "P3\n");
	cursor = ft_strcpy_end(cursor, _width);
	cursor = ft_strcpy_end(cursor, " ");
	cursor = ft_strcpy_end(cursor, _height);
	cursor = ft_strcpy_end(cursor, "\n255\n");
	free(_width);
	free(_height);
	return (cursor);
}

char	*write_pixel_to_buffer(t_mlx_img *img, char *cursor, int x, int y)
{
	int		color;
	char	*red;
	char	*green;
	char	*blue;

	color = mlx_get_pixel_from_img(img, x, y);
	red = ft_itoa(get_red(color));
	green = ft_itoa(get_green(color));
	blue = ft_itoa(get_blue(color));
	cursor = ft_strcpy_end(cursor, red);
	cursor = ft_strcpy_end(cursor, " ");
	cursor = ft_strcpy_end(cursor, green);
	cursor = ft_strcpy_end(cursor, " ");
	cursor = ft_strcpy_end(cursor, blue);
	cursor = ft_strcpy_end(cursor, " ");
	free(red);
	free(green);
	free(blue);
	return (cursor);
}

char	*make_ppm_img(t_mlx_img *img, char *cursor)
{
	int	x;
	int	y;

	x = 0;
	while (x < img->_width)
	{
		y = 0;
		while (y < img->_height)
		{
			cursor = write_pixel_to_buffer(img, cursor, x, y);
			y++;
		}
		cursor = ft_strcpy_end(cursor, "\n");
		x++;
	}
	return (cursor);
}

void	mlx_save_img_to_ppm(t_mlx_img *img, char *filename)
{
	char	*buffer;
	char	*cursor;
	size_t	buffer_size;

	buffer_size = 250 + (12 * img->_width + 1) * img->_height;
	buffer = ft_calloc(buffer_size, sizeof(char));
	cursor = buffer;
	cursor = make_ppm_header(img, cursor);
	cursor = make_ppm_img(img, cursor);
	save_ppm_file(buffer, filename);
	free(buffer);
}
