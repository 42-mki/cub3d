/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 20:54:44 by seoh              #+#    #+#             */
/*   Updated: 2020/04/22 17:43:33 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	str_length(const char *dest)
{
	unsigned int	cnt;

	cnt = 0;
	while (dest[cnt] != '\0')
		cnt++;
	return (cnt);
}

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	char			*dst;
	const char		*src_start;
	unsigned int	dst_digit;
	unsigned int	remain;

	dst = dest;
	src_start = src;
	remain = dstsize;
	while (remain-- != 0 && *dst != '\0')
		dst++;
	dst_digit = dst - dest;
	remain = dstsize - dst_digit;
	if (remain == 0)
		return (dst_digit + str_length(src));
	while (*src != '\0')
	{
		if (remain > 1)
		{
			*dst++ = *src;
			remain--;
		}
		src++;
	}
	*dst = '\0';
	return (dst_digit + (src - src_start));
}
