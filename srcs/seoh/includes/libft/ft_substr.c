/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 05:07:56 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 19:56:11 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	size;
	char	*rtn;

	if (s == 0)
		return (0);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	if ((rtn = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	size = ft_strlen(s);
	i = 0;
	while (i < len && i + start < size)
	{
		rtn[i] = s[start + i];
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
