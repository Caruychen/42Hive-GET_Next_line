/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_stdout.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 10:35:46 by cchen             #+#    #+#             */
/*   Updated: 2021/12/16 16:30:08 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	test_stdout(void (f)(char const *))
{
	char	*line;
	int		res;

	while ((res = get_next_line(fileno(stdin), &line)))
	{
		f(line);
		ft_strdel(&line);
	}
	return (0);
}
