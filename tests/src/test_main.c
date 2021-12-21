/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 13:38:45 by cchen             #+#    #+#             */
/*   Updated: 2021/12/21 14:02:01 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testgnl.h"

int	main(int argc, char **argv)
{
	if (argc < 3)
	{
		if (*argv[1] == '1')
			return(test_stdout(ft_putendl));
		if (*argv[1] == '0')
			return(test_stdout(ft_putstr));
		if (*argv[1] == '2')
			return (test_error());
		if (*argv[1] == '3')
			return (test_multifile());
		return (0);
	}
	if (*argv[1] == '1')
		return(test_readfile(argv[2], ft_putendl_fd));
	if (*argv[1] == '0')
		return(test_readfile(argv[2], ft_putstr_fd));
	return (0);
}
