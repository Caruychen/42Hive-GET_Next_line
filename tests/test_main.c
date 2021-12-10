/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:45 by cchen             #+#    #+#             */
/*   Updated: 2021/12/10 15:22:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"
#include <fcntl.h>

int	main(void)
{
	int	fd;
	int	lines;
	char	*line;
	int	res;

	fd = open("text_files/text1.txt", O_RDONLY);
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
		ft_putstr(" : ");
		ft_putendl(line);
	}
	if (close(fd) == -1)
	{
		ft_putendl("Error while closing file.");
		return (1);
	}
	return (0);
}
