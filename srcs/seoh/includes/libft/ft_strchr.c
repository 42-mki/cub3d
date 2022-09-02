/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 10:25:51 by seoh              #+#    #+#             */
/*   Updated: 2020/04/10 04:32:43 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int idx;

	idx = 0;
	while (s[idx] != '\0')
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx++;
	}
	if (c == '\0')
		return ((char *)s + idx);
	return (0);
}
