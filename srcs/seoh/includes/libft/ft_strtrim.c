/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 06:51:37 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 15:05:00 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*result;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && ft_strchr(set, *(s1)))
		s1++;
	len = ft_strlen(s1);
	while (len && ft_strchr(set, *(s1 + len)))
		len--;
	result = ft_substr((char*)s1, 0, len + 1);
	return (result);
}

/*
** int main()
** {
** 	printf("%s\n", ft_strtrim("babcdeab","ab"));
** }
*/
