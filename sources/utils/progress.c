/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   progress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:48:03 by ppaulo-d          #+#    #+#             */
/*   Updated: 2023/01/27 12:48:50 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minirt.h>

static char *write_int(int n, char *dest)
{
	char	num;
	char	num_str[2];

	num = n % 10 + 48;
	if (n / 10 != 0)
		dest = write_int(n / 10, dest);
	num_str[0] = num;
	num_str[1] = 0;
	dest = ft_strcpy_end(dest, num_str);
	return (dest);
}

static char	*write_double(double n, char *buffer)
{
	int		intpart;
	double	fpart;
	int		fi_part;
	char	*cursor;

	intpart = (int) n;
	fpart = n - (double) intpart;
	if (fpart < 0)
		fpart *= -1.0;
	fi_part = (int) (fpart * (int)pow(10, 1));
	cursor = write_int(intpart, buffer);
	cursor = ft_strcpy_end(cursor, ".");
	cursor = write_int(fi_part, cursor);
	return (cursor);
}

void	print_progress(int x, int y)
{
	t_camera		cam;
	static char		*buffer;
	char			*cursor;
	double			percentage;
	
	cam = *camera();
	if (buffer == NULL)
		buffer = malloc(10 * sizeof(char));
	ft_bzero(buffer, 10);
	cursor = ft_strcpy_end(buffer, "\r");
	percentage = ((double) (x * y)) * 100.0 / (double)(cam.vsize * cam.hsize);
	cursor = write_double(percentage, cursor);
	*cursor++ = '%';
	if (x == cam.hsize)
		cursor = ft_strcpy_end(cursor, "\n");
	ft_putstr_fd(buffer, 1);
	if (x == cam.hsize)
		free(buffer);
}
