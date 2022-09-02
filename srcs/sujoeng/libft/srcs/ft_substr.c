/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:46:17 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:46:20 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	i;
	unsigned int	y;

	i = start;
	y = 0;
	if (!s)
		return (NULL);
	if (!(str = malloc((int)len + 1)))
		return (NULL);
	while (s[i] && y < (unsigned int)len && start < ft_strlen(s))
	{
		str[y] = s[i];
		i++;
		y++;
	}
	str[y] = '\0';
	return (str);
}
