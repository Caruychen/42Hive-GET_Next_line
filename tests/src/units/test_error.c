/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:49:21 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 14:05:19 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	test_error(void)
{
	char	*line;
	int		res;

	res = get_next_line(42, &line);
	line = malloc(10);
	free(line);
	if (res != -1)
		return (1);
	return (0);
}
