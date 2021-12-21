/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vecfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 15:05:04 by cchen             #+#    #+#             */
/*   Updated: 2021/12/20 15:10:12 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_vecfree(t_vec *src)
{
	ft_memdel(&src->memory);
	src->alloc_size = 0;
	src->elem_size = 0;
	src->len = 0;
}
