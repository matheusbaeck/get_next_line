/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:34:56 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/07 22:54:11 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include "limits.h"
# include <unistd.h>
# include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
char	*ft_strjoin(const char *s1, const char *s2);
char	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *b, size_t len);
char	*get_str(char **line, char *break_point, int red);
int		keep_reading(int fd, char **line);
char	*get_next_line(int fd);

#endif