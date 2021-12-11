/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2021/12/11 16:20:21 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	assign_line(char **s_arr, char **line, int bytes)
{
	int		len;
	char	*temp;

	if (bytes < 0)
		return (-1);
	if (bytes == 0 && *s_arr == NULL)
		return (0);
	len = 0;
	while ((*s_arr)[len] != '\0' && (*s_arr)[len] != '\n')
		++len;
	if ((*s_arr)[len] == '\n')
	{
		*line = ft_strsub(*s_arr, 0, len);
		temp = ft_strdup(&((*s_arr)[len + 1]));
		ft_strdel(s_arr);
		*s_arr = temp;
		if (**s_arr == '\0')
			ft_strdel(s_arr);
		return (1);
	}
	*line = ft_strdup(*s_arr);
	ft_strdel(s_arr);
	return (1);
}

static int	read_file(const int fd, char *buff, int *bytes)
{
	*bytes = read(fd, buff, BUFF_SIZE);
	return (*bytes);
}

static void	store_buff(char **s, char *buff, int bytes)
{
	char	*temp;

	buff[bytes] = '\0';
	if (*s == NULL)
	{
		*s = ft_strdup(buff);
		return ;
	}
	temp = ft_strjoin(*s, buff);
	ft_strdel(s);
	*s = temp;
}

int	get_next_line(const int fd, char **line)
{
	int			bytes;
	static char	*s_arr[FD_MAX];
	char		buff[BUFF_SIZE + 1];

	if (fd < 0 || line == NULL)
		return (-1);
	while (read_file(fd, buff, &bytes) > 0)
	{
		store_buff(&s_arr[fd], buff, bytes);
		if (ft_strchr(buff, '\n'))
			break ;
	}
	return (assign_line(&s_arr[fd], line, bytes));
}
