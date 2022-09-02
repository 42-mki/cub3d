/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/01 08:41:45 by seoh              #+#    #+#             */
/*   Updated: 2020/04/10 04:32:07 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	idx;

	idx = ft_strlen((char *)s);
	while (idx >= 0)
	{
		if (s[idx] == (char)c)
			return ((char *)s + idx);
		idx--;
	}
	return (0);
}
