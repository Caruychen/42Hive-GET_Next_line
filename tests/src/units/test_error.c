/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:49:21 by cchen             #+#    #+#             */
/*   Updated: 2021/12/29 15:30:17 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	test_error(void)
{
	char	*line;
	int		res;

	res = get_next_line(-1, &line);
	if (res != -1)
		return (1);
	res = get_next_line(42, &line);
	if (res != -1)
		return (1);
	res = get_next_line(9000, &line);
	if (res != -1)
		return (1);
	res = get_next_line(FD_MAX, &line);
	if (res != -1)
		return (1);
	res = get_next_line(FD_MAX + 1, &line);
	if (res != -1)
		return (1);
	res = get_next_line(FD_MAX * 4, &line);
	if (res != -1)
		return (1);
	return (0);
}
