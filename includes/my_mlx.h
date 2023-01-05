/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_mlx.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 11:26:12 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/05 17:54:54 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_MLX_H
# define MY_MLX_H

# include "mlx.h"
# include "libft.h"
# include <fcntl.h>

/* MLX*/

void		*mlx_data(void);
void		start_mlx(void);
void		*window(void);

/* IMAGE */

typedef struct	s_mlx_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		width;
	int		height;
}			t_mlx_img;

void		img_init(void);
t_mlx_img	*image(void);

void		mlx_draw_pixel(t_mlx_img *img, int x, int y, int color);
int			mlx_get_pixel_from_img(t_mlx_img *img, int x, int y);

/* COLORS */

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}			t_rgb;

int		get_red(int color);
int		get_green(int color);
int		get_blue(int color);
int		get_color(int red, int green, int blue);
int		get_rgb_color(t_rgb rgb);
t_rgb	color_rgb(int red, int green,  int blue);

/* PPM file*/

void	mlx_save_img_to_ppm(t_mlx_img *img, char *filename);

#endif