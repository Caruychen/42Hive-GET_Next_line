/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:45:12 by cchen             #+#    #+#             */
/*   Updated: 2021/12/16 10:19:11 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	test_readfile(const char *arg1, const char *arg2)
{
	int		fd_src;
	int		fd_dst;
	char	*line;
	int		res;

	fd_src = open(arg1, O_RDONLY);
	fd_dst = open(arg2, O_CREAT|O_TRUNC|O_RDWR, 0666);
	if (fd_src == -1 || fd_dst == -1)
	{
		ft_putendl("Error while opening file from main.");
		return (1);
	}
	while ((res = get_next_line(fd_src, &line)))
	{
		ft_putendl_fd(line, fd_dst);
		ft_strdel(&line);
	}
	if (close(fd_src) == -1 || close(fd_dst) == -1)
	{
		ft_putendl("Error while closing file.");
		return (1);
	}
	return (0);
}
