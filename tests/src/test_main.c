/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:45 by cchen             #+#    #+#             */
/*   Updated: 2021/12/16 17:22:32 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		if (*argv[1] == '1')
			test_stdout(ft_putendl);
		else if (*argv[1] == '0')
			test_stdout(ft_putstr);
		else if (*argv[1] == '2')
		{
			return (test_error());
		}
		return (0);
	}
	if (*argv[1] == '1')
		test_readfile(argv[2], ft_putendl_fd);
	else if (*argv[1] == '0')
		test_readfile(argv[2], ft_putstr_fd);
	return (0);
}
