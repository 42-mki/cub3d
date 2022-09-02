/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 06:10:00 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 06:24:18 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	int		len;
	int		len2;
	int		i;

	len = ft_strlen(s1);
	len2 = ft_strlen(s2);
	if ((rtn = (char *)malloc(sizeof(char) * (len + len2 + 1))) == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		rtn[i] = s1[i];
		i++;
	}
	while (i < len + len2)
	{
		rtn[i] = s2[i - len];
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
