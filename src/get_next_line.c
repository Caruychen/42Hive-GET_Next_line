/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 21:09:09 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	push_line(t_vec *buff, char **line)
{
	size_t	index;

	index = 0;
	while (((char*)buff->memory)[index] != '\n' && index < buff->len)
		++index;
	*line = ft_strsub(buff->memory, 0, index);
	if (!*line)
		return (-1);
	if (index == buff->len)
		buff->len = 0;
	else
	{
		buff->len = buff->len - (index + 1);
		ft_memcpy(buff->memory, &buff->memory[index + 1], buff->len);
	}
	return (1);
}

static int	result(t_vec *buff, char **line, int bytes)
{
	int	result;

	if (bytes < 0)
	{
		ft_vecfree(buff);
		return (-1);
	}
	if (bytes == 0)
	{
		if (!buff->memory)
			return (0);
		push_line(buff, line);
		ft_vecfree(buff);
		//FIX!!!
		return (1);
	}
	result = push_line(buff, line);
	if (result == -1 && buff->memory)
		ft_vecfree(buff);
	return (result);
}

int	get_next_line(const int fd, char **line)
{
	int				bytes;
	static t_vec	vectors[FD_MAX];
	t_vec			*buff;
	size_t			len;

	if (fd < 0 || !line)
		return (-1);
	buff = &vectors[fd];
	if (!buff->memory)
		ft_vecnew(buff, BUFF_SIZE, sizeof(char));
	while (1)
	{
		len = buff->len * buff->elem_size;
		if (buff->alloc_size - len < BUFF_SIZE)
			ft_vecresize(buff, buff->alloc_size * 2);
		bytes = read(fd, (char *)buff->memory + len, BUFF_SIZE);
		if (bytes <= 0)
			break ;
		buff->len += bytes / buff->elem_size;
		if (ft_memchr(buff->memory + len, '\n', bytes))
			break ;
	}
	return (result(buff, line, bytes));
}
