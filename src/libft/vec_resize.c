/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_resize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchen <cchen@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:06:39 by cchen             #+#    #+#             */
/*   Updated: 2022/01/01 13:31:58 by cchen            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	vec_resize(t_vec *src, size_t target_size)
{
	t_vec	dst;
	size_t	target_len;

	if (!src)
		return (-1);
	target_len = target_size / src->elem_size;
	if (vec_new(&dst, target_len, src->elem_size) < 0)
		return (-1);
	vec_copy(&dst, src);
	dst.len = ft_imin(target_len, src->len);
	vec_free(src);
	*src = dst;
	return (target_size);
}
