/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:46 by cchen             #+#    #+#             */
/*   Updated: 2021/12/16 10:39:30 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	test_stdout(void)
{
	char	*line;
	int	res;

	while ((res = get_next_line(fileno(stdin), &line)))
	{
		ft_putendl(line);
		ft_strdel(&line);
	}
	return (0);
}
