/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:18:50 by seoh              #+#    #+#             */
/*   Updated: 2020/04/25 23:39:33 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*temp;
	unsigned char	*tempcpy;
	size_t			i;

	if (dest == 0 && src == 0)
		return (dest);
	i = 0;
	tempcpy = (unsigned char *)dest;
	temp = (unsigned char *)src;
	while (n)
	{
		*tempcpy++ = *temp++;
		n--;
	}
	return (dest);
}
