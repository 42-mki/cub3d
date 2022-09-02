/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 16:30:42 by seoh              #+#    #+#             */
/*   Updated: 2020/04/10 04:31:16 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	chr;

	chr = c;
	i = 0;
	while (i < n)
	{
		if ((((unsigned char *)dst)[i] = ((unsigned char *)src)[i]) == chr)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
