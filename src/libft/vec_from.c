/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_from.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 16:04:59 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 13:31:27 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vec_from(t_vec *dst, void *src, size_t len, size_t elem_size)
{
	if (!dst || !src || len == 0 || elem_size == 0)
		return (-1);
	vec_new(dst, len, elem_size);
	if (dst->alloc_size == 0)
		return (-1);
	dst->len = len;
	dst->memory = ft_memcpy(dst->memory, src, dst->alloc_size);
	return (dst->alloc_size);
}
