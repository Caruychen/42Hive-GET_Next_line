/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 12:54:33 by cchen             #+#    #+#             */
/*   Updated: 2021/12/23 15:52:24 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32
# define FD_MAX 8192
# define RESIZE_FACTOR 2

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

int	get_next_line(const int fd, char **line);

#endif
