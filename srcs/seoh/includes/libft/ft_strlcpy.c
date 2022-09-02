/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 05:34:39 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 04:38:16 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	cnt;
	size_t	idx;

	cnt = 0;
	idx = 0;
	if (dst == 0 || src == 0)
		return (0);
	while (src[cnt] != '\0')
		cnt++;
	if (size != 0)
	{
		while (src[idx] != '\0' && idx < (size - 1))
		{
			dst[idx] = src[idx];
			idx++;
		}
		dst[idx] = '\0';
	}
	return (cnt);
}
