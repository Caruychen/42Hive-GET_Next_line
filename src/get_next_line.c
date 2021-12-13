/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2021/12/13 15:14:26 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	read_line(const int fd, char *buff, int *bytes)
{
	if (ft_strchr(buff, '\n'))
		return (0);
	*bytes = read(fd, buff, BUFF_SIZE);
	return (*bytes);
}

static int	cpy_buff(char **s, char *buff)
{
	char	*temp;

	if (*s == NULL)
	{
		*s = ft_strdup(buff);
		return (-(*s == NULL));
	}
	temp = ft_strjoin(*s, buff);
	free(*s);
	*s = temp;
	return (-(*s == NULL));
}

static int	push_line(char **s, char **line)
{
	char	*temp;

	temp = *s;
	while (*temp != '\0' && *temp != '\n')
		++temp;
	if (*temp == '\n')
	{
		*line = ft_strsub(*s, 0, temp - *s);
		temp = ft_strdup(++temp);
		free(*s);
		*s = temp;
		if (*line == NULL || *s == NULL)
			return (-1);
		if (**s == '\0')
			ft_strdel(s);
		return (1);
	}
	*line = ft_strdup(*s);
	ft_strdel(s);
	if (*line == NULL)
		return (-1);
	return (1);
}

static int	result(char **s, char **line, int bytes)
{
	int	result;

	if (bytes < 0)
	{
		if (*s)
			ft_strdel(s);
		return (-1);
	}
	if (bytes == 0 && *s == NULL)
		return (0);
	result = push_line(s, line);
	if (result == -1 && *s)
		ft_strdel(s);
	return (result);
}

int	get_next_line(const int fd, char **line)
{
	int			bytes;
	static char	*s_arr[FD_MAX];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	buff[0] = '\0';
	while (read_line(fd, buff, &bytes) > 0)
	{
		buff[bytes] = '\0';
		if (cpy_buff(&s_arr[fd], buff) == -1)
			return (result(&s_arr[fd], line, -1));
	}
	return (result(&s_arr[fd], line, bytes));
}
