/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:45 by cchen             #+#    #+#             */
/*   Updated: 2021/12/13 14:27:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int	fd;
	int	lines;
	char	*line;
	int	res;
	char	*file;

	if (argc < 2)
	{
		ft_putendl("Error: Need to enter test with argument");
		return (1);
	}
	file = ft_strjoin("text_files/", argv[1]);
	if (!file)
	{
		ft_putendl("Error in ft_strjoin.");
		return (1);
	}
	fd = open(file, O_RDONLY);
	lines = 0;
	if (fd == -1)
	{
		ft_putendl("Error while opening file.");
		return (1);
	}
	while ((res = get_next_line(fd, &line)))
	{
		lines += res;
		ft_putstr("Line ");
		ft_putnbr(lines);
		ft_putstr(": ");
		ft_putendl(line);
	}
	if (close(fd) == -1)
	{
		ft_putendl("Error while closing file.");
		return (1);
	}
	return (0);
}
