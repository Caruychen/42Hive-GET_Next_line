/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgnl.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/14 14:04:11 by cchen             #+#    #+#             */
/*   Updated: 2021/12/17 13:20:56 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTGNL_H
# define TESTGNL_H

# include <stdio.h>
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

int	test_readfile(const char *argv, void (f)(char const *, int));
int	test_stdout(void (f)(char const *));
int	test_error(void);
int	test_readmultifile(void);

#endif
