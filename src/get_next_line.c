/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 11:45:43 by cchen             #+#    #+#             */
/*   Updated: 2021/12/22 12:00:33 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	buff_reset(t_vec *buff, size_t index)
{
	if (index == buff->len)
	{
		buff->len = 0;
		return (1);
	}
	buff->len = buff->len - (index + 1);
	ft_memcpy(buff->memory, &buff->memory[index + 1], buff->len);
	return (1);
}

static int	push_line(t_vec *buff, char **line)
{
	size_t	index;

	index = 0;
	while (((char *)buff->memory)[index] != '\n' && index < buff->len)
		++index;
	*line = ft_strsub(buff->memory, 0, index);
	if (!*line)
	{
		ft_vecfree(buff);
		return (-1);
	}
	return (buff_reset(buff, index));
}

static int	result(t_vec *buff, char **line, int bytes)
{
	if (bytes < 0 || (!bytes && !buff->len))
	{
		ft_vecfree(buff);
		return (bytes);
	}
	return (push_line(buff, line));
}

static int	read_line(int fd, t_vec *buff, int *bytes, size_t *offset)
{
	*offset = buff->len * buff->elem_size;
	if (buff->alloc_size - *offset < BUFF_SIZE
		&& ft_vecresize(buff, buff->alloc_size * RESIZE_FACTOR) == -1)
		return (*bytes = -1);
	return (*bytes = read(fd, buff->memory + *offset, BUFF_SIZE));
}

int	get_next_line(const int fd, char **line)
{
	static t_vec	vectors[FD_MAX];
	t_vec			*buff;
	int				bytes;
	size_t			offset;

	buff = &vectors[fd];
	if (fd < 0 || !line)
		return (-1);
	if (!buff->memory && ft_vecnew(buff, BUFF_SIZE, sizeof(char)) == -1)
		return (-1);
	while (read_line(fd, buff, &bytes, &offset) > 0)
	{
		buff->len += bytes / buff->elem_size;
		if (ft_memchr(buff->memory + offset, '\n', bytes))
			break ;
	}
	return (result(buff, line, bytes));
}
