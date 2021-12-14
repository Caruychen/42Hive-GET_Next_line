/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:45 by cchen             #+#    #+#             */
/*   Updated: 2021/12/14 16:39:29 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
	{
		ft_putendl("Error: Need to enter test with argument");
		return (1);
	}
	if (atoi(argv[1]) == 1)
	{
		if (argc < 4)
		{
			ft_putendl("Error: Need to enter test num with 2 text file names");
			return (1);
		}
		test1(argv[2], argv[3]);
	}
	return (0);
}
