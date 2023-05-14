/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reda.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 01:14:10 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/08 01:16:53 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	char static	str[30];
	int		fd;

	fd = open("file0.txt", 2);
	read(fd, str, 2);
	read(fd, str, 2);
	read(fd, str, 2);
	read(fd, str, 2);
	return (0);
}
