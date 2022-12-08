/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppaulo-d <ppaulo-d@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 00:53:11 by ppaulo-d          #+#    #+#             */
/*   Updated: 2022/08/07 17:32:16 by ppaulo-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_buffer(int fd, char *buffer, char ***s_buffer);
static void	fill_buffer(int fd, char **s_buffer);
static char	*fill_line(char *s_buffer, char **line);

/** This function reads and return a line from a file descriptor.
 * @param fd The file descriptor from which to read.
 * @return On success, it returns the line read. The line string is allocated
 * with malloc(3). NULL is returned on error or EOF.
 * */
char	*get_next_line(int fd)
{
	static char	*s_buffer[1500];
	char		*line;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	fill_buffer(fd, &s_buffer[fd]);
	if (!s_buffer[fd])
		return (NULL);
	s_buffer[fd] = fill_line(s_buffer[fd], &line);
	if (ft_strlen(line) == 0)
	{
		free(line);
		free(s_buffer[fd]);
		s_buffer[fd] = NULL;
		return (NULL);
	}
	return (line);
}

static void	check_buffer(int fd, char *buffer, char ***s_buffer)
{
	int		index;
	int		b_read;
	char	*temp_sbuffer;

	index = 0;
	while (buffer[index] && buffer[index] != '\n')
	{
		if (!buffer[index + 1])
		{
			b_read = read(fd, buffer, BUFFER_SIZE);
			buffer[b_read] = 0;
			if (b_read > 0)
			{
				temp_sbuffer = ft_strdup(**s_buffer);
				free(**s_buffer);
				**s_buffer = ft_strjoin(temp_sbuffer, buffer);
				free(temp_sbuffer);
			}
			index = -1;
		}
		index++;
	}
	free(buffer);
}

static void	fill_buffer(int fd, char **s_buffer)
{
	int		b_read;
	char	*buffer;
	char	*temp_sbuffer;

	buffer = malloc((BUFFER_SIZE * sizeof(char) + 1));
	if (buffer == NULL)
		return ;
	b_read = read(fd, buffer, BUFFER_SIZE);
	if (b_read >= 0 && buffer)
		buffer[b_read] = 0;
	else
	{	
		free(buffer);
		return ;
	}
	if (*s_buffer == NULL && b_read >= 0 && ft_strlen(buffer))
		*s_buffer = ft_strdup(buffer);
	else if (ft_strlen(buffer) && *s_buffer)
	{
		temp_sbuffer = ft_strdup(*s_buffer);
		free(*s_buffer);
		*s_buffer = ft_strjoin(temp_sbuffer, buffer);
		free(temp_sbuffer);
	}
	check_buffer(fd, buffer, &s_buffer);
}

static char	*fill_line(char *s_buffer, char **line)
{
	int		index;
	int		l_len;
	char	*new_sbuffer;

	if (s_buffer == NULL)
		return (NULL);
	index = -1;
	l_len = 0;
	while (index++, s_buffer[index] && s_buffer[index] != '\n')
		l_len++;
	if (s_buffer[index] == '\n')
		l_len++;
	*line = malloc(sizeof(char) * l_len + 1);
	index = -1;
	while (index++, s_buffer[index] && s_buffer[index] != '\n')
		(*line)[index] = s_buffer[index];
	if (s_buffer[index] == '\n')
	{
		(*line)[index] = '\n';
		index++;
	}
	(*line)[index] = 0;
	new_sbuffer = ft_substr(s_buffer, index, ft_strlen(s_buffer) - index);
	free(s_buffer);
	return (new_sbuffer);
}
