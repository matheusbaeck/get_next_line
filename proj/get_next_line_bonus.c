/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 01:40:18 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/08 00:10:22 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
#include <fcntl.h>
#include <stdio.h>

void	*ft_bzero(void *b, size_t len)
{
	unsigned int	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char) '\0';
		i++;
	}
	return (b);
}

char	*get_str(char **line, char *break_point, int red)
{
	char		*str_to_return;
	char		*line_temp;
	ssize_t		str_len;
	ssize_t		line_len;

	str_len = 0;
	while (!(line[0][str_len] == '\n'
		|| line[0][str_len] == '\0'))
		str_len++;
	if (line[0][str_len] == '\n')
		str_len++;
	if (!break_point && red <= 0 && !(**line))
		return (0);
	str_to_return = ft_calloc(str_len + 1, sizeof(char));
	ft_strlcpy(str_to_return, *line, str_len + 1);
	line_temp = *line;
	line_len = ft_strlen(&line_temp[str_len]);
	*line = ft_calloc(line_len + 1, sizeof(char));
	ft_strlcpy(*line, &line_temp[str_len], line_len + 1);
	free(line_temp);
	return (str_to_return);
}

int	keep_reading(int fd, char **line)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*line_temp;
	int		red;

	ft_bzero(buffer, BUFFER_SIZE + 1);
	red = read(fd, buffer, BUFFER_SIZE);
	if (red < 0)
	{
		free(*line);
		*line = NULL;
		return (red);
	}
	if (!(*line))
		*line = ft_calloc(1, sizeof(char *));
	line_temp = *line;
	*line = ft_strjoin(*line, buffer);
	free(line_temp);
	return (red);
}

char	*get_next_line(int fd)
{
	static	char	*(line[OPEN_MAX]);
	void			*break_point;
	char			*str_to_return;
	int				red;

	red = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	break_point = NULL;
	while (!break_point && red > 0)
	{
		if (line[fd])
			break_point = ft_memchr(line[fd], '\n', ft_strlen(line[fd]));
		if (!break_point)
			red = keep_reading(fd, &(line[fd]));
		if (red < 0)
			return (0);
	}
	str_to_return = get_str(&line[fd], break_point, red);
	if (!str_to_return)
		return (free(line[fd]), line[fd] = 0, NULL);
	return (str_to_return);
}
