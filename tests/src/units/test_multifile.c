/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_multifile.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 13:03:14 by cchen             #+#    #+#             */
/*   Updated: 2021/12/17 14:27:35 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

static int	run_gnl(int fs, int fd)
{
	char	*line;
	int		res;

	res = get_next_line(fs, &line);
	ft_putendl_fd(line, fd);
	ft_strdel(&line);
	return (res);
}

int	test_multifile(void)
{
	int		fs1;
	int		fs2;
	int		fs3;
	int		fd1;
	int		fd2;
	int		fd3;
	int		res = 1;

	fs1 = open("text_files/bonus/multi1.txt", O_RDONLY);
	fs2 = open("text_files/bonus/multi2.txt", O_RDONLY);
	fs3 = open("text_files/bonus/multi3.txt", O_RDONLY);
	fd1 = open("text_files/bonus/multi1.output", O_CREAT|O_TRUNC|O_RDWR, 0666);
	fd2 = open("text_files/bonus/multi2.output", O_CREAT|O_TRUNC|O_RDWR, 0666);
	fd3 = open("text_files/bonus/multi3.output", O_CREAT|O_TRUNC|O_RDWR, 0666);
	if (fs1 == -1 || fs2 == -1 || fs3 == -1 || fd1 == -1 || fd2 == -1 || fd3 == -1)
	{
		ft_putendl("Error while opening files.");
		return (1);
	}
	while (res)
	{
		res = run_gnl(fs1, fd1);
		res = res || run_gnl(fs2, fd2);
		res = res || run_gnl(fs3, fd3);
	}
	if (close(fs1) == -1 || close(fs2) == -1 || close(fs3) == -1 ||
		close(fd1) == -1 || close(fd2) == -1 || close(fd3) == -1)
	{
		ft_putendl("Error while closing file.");
		return (1);
	}
	return (0);
}
