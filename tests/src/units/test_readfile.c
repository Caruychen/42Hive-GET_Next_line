/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_readfile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 13:45:12 by cchen             #+#    #+#             */
/*   Updated: 2021/12/16 16:23:38 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

static char	*ft_resuffix(const char *argv, const char *str)
{
	size_t	len;
	char	*temp;
	char	*dst;

	len = strchr(argv, '.') - argv;
	temp = ft_strsub(argv, 0, len);
	dst = ft_strjoin(temp, str);
	ft_strdel(&temp);
	return (dst);
}

int	test_readfile(const char *argv, void (f)(char const *, int))
{
	int		fd_src;
	int		fd_dst;
	char	*line;
	int		res;
	char	*dstname;

	dstname = ft_resuffix(argv, ".output");
	fd_src = open(argv, O_RDONLY);
	fd_dst = open(dstname, O_CREAT|O_TRUNC|O_RDWR, 0666);
	if (fd_src == -1 || fd_dst == -1)
	{
		ft_putendl("Error while opening file from main.");
		free(dstname);
		return (1);
	}
	while ((res = get_next_line(fd_src, &line)))
	{
		f(line, fd_dst);
		ft_strdel(&line);
	}
	free(dstname);
	if (close(fd_src) == -1 || close(fd_dst) == -1)
	{
		ft_putendl("Error while closing file.");
		return (1);
	}
	return (0);
}
