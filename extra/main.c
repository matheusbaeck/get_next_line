/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamagalh@student.42madrid.com <mamagalh    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 22:23:32 by mamagalh@st       #+#    #+#             */
/*   Updated: 2023/03/06 02:28:25 by mamagalh@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include "get_next_line.h"

void	find_leaks(void)
{
	system("leaks -q main.out");
}

int	run_test(char *cfd, char *cfd_exit)
{
	char	*str;
	int		count;
	int		fd;
	int		fd_exit;

	//atexit(find_leaks);
	fd = open(cfd, 2);
	fd_exit = open(cfd_exit, 2);
	count = 0;
	while (count <= 2147483646)
	{
		str = get_next_line(fd);
		if (str)
		{
			if (*str)
			{
				write(fd_exit, str, strlen(str));
				free(str);
			}
			else
			{
				write(1, cfd, 11);
				write(1, "    exit 1 NULL\n", 16);
				free(str);
				return (1);
			}
		}
		else if ((count % 2) == 0)
		{
			write(1, cfd, 11);
			write(1, "    exit 2 NULL\n", 16);
			system("leaks -q main.out");
			return (2);
		}
		count++;
	}
	free(str);
	return (0);
}

int	run_test_bad(char *cfd, char *cfd_exit)
{
	char	*str;
	int		count;
	int		fd;
	int		fd_exit;
	int		bad_fd;

	//atexit(find_leaks);
	fd = open(cfd, 2);
	fd_exit = open(cfd_exit, 2);
	bad_fd = 5;
	count = 0;
	while (count <= 2147483646)
	{
		if ((count % 2) == 0)
		{
			str = get_next_line(fd);
		}
		else
		{
			str = get_next_line(bad_fd);
		}
		if (str)
		{
			if (*str)
			{
				write(fd_exit, str, strlen(str));
				free(str);
			}
			else
			{
				write(1, cfd, 11);
				write(1, "    exit 1 NULL\n", 16);
				free(str);
				return (1);
			}
		}
		else if ((count % 2) == 0)
		{
			write(1, cfd, 11);
			write(1, "    exit 2 NULL\n", 16);
			system("leaks -q main.out");
			return (2);
		}
		count++;
	}
	free(str);
	return (0);
}

int	run_test_bonus(char *cfd, char *cfd_exit, char *cfd2, char *cfd_exit2)
{
	char	*str;
	char	*str2;
	int		count;
	int		end;
	int		fd;
	int		fd_exit;
	int		fd2;
	int		fd_exit2;

	fd = open(cfd, 2);
	fd_exit = open(cfd_exit, 2);
	fd2 = open(cfd2, 2);
	fd_exit2 = open(cfd_exit2, 2);
	count = 0;
	end = 0;
	count = 0;
	while (count <= 2147483646)
	{
		str = get_next_line(fd);
		str2 = get_next_line(fd2);
		if (str)
		{
			if (*str)
			{
				write(fd_exit, str, strlen(str));
				write(fd_exit2, str2, strlen(str2));
				free(str);
				free(str2);
			}
			else
			{
				write(1, cfd, 11);
				write(1, "    exit 1 NULL\n", 16);
				free(str);
				return (1);
			}
		}
		else if ((count % 2) == 0)
		{
			write(1, cfd, 11);
			write(1, "    exit 2 NULL\n", 16);
			system("leaks -q main.out");
			return (2);
		}
		count++;
	}
	free(str);
	return (0);
}

int	main(void)
{
	//atexit(find_leaks);
	run_test("files/file0.txt" , "files/file0_exit.txt");
	run_test("files/file1.txt" , "files/file1_exit.txt");
	run_test("files/file2.txt" , "files/file2_exit.txt");
	run_test("files/file3.txt" , "files/file3_exit.txt");
	run_test("files/file4.txt" , "files/file4_exit.txt");
	run_test("files/file5.txt" , "files/file5_exit.txt");
	run_test("files/file6.txt" , "files/file6_exit.txt");
	run_test("files/file7.txt" , "files/file7_exit.txt");
	run_test("files/file8.txt" , "files/file8_exit.txt");
	run_test_bad("files/file9.txt" , "files/file9_exit.txt");
	run_test_bonus("files/file11.txt" , "files/file11_exit.txt"
		, "files/file12.txt" , "files/file12_exit.txt");
	return (0);
}
