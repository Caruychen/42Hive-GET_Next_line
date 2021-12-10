/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2021/12/10 16:39:53 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	assign_line(char **s_arr, char **line, int bytes, int fd)
{
	int		len;
	char	*temp;

	if (bytes < 0)
		return (-1);
	else if (bytes == 0 && s_arr[fd] == NULL)
		return (0);
	len = 0;
	while ((*s_arr) 
}

static int	read_file(const int fd, char **buff, int *bytes)
{
	*bytes = read(fd, *buff, BUFF_SIZE);
	return (*bytes);
}

static void	store_buff(char **s_arr, char *buff, int bytes, int fd)
{
	char	*temp;

	buff[bytes] = '\0';
	if (s_arr[fd] == NULL)
	{
		s_arr[fd] = ft_strdup(buff);
		return ();
	}
	temp = ft_strjoin(s_arr[fd], buff);
	ft_strdel(&s_arr[fd]);
	s = temp;
}

int	get_next_line(const int fd, char **line)
{
	int			bytes;
	static char	*s_arr[FD_MAX];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while (read_file(fd, &buff, &bytes) > 0)
	{
		store_buff(s_arr, buff, bytes, fd);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (assign_line(s_arr, line, bytes, fd));
}
