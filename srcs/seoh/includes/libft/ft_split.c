/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 23:21:25 by seoh              #+#    #+#             */
/*   Updated: 2020/04/27 13:57:40 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		count_delimiter(const char *s, char c)
{
	int				is_word;
	unsigned int	cnt;

	cnt = 0;
	is_word = 0;
	while (*s != '\0')
	{
		if (is_word == 0 && *s != c)
		{
			cnt++;
			is_word = 1;
		}
		else if (is_word == 1 && *s == c)
			is_word = 0;
		s++;
	}
	return (cnt);
}

int		order_word(char *s, char c, int order)
{
	int	is_word;
	int	cnt;
	int position;

	is_word = 0;
	cnt = 0;
	position = 0;
	while (s[position] != '\0')
	{
		if (is_word == 0 && s[position] != c)
		{
			cnt++;
			if (cnt == order + 1)
				break ;
			is_word = 1;
		}
		else if (is_word == 1 && s[position] == c)
			is_word = 0;
		position++;
	}
	return (position);
}

char	*put_word(const char *s, char c)
{
	int		i;
	int		len;
	char	*rtn;

	i = 0;
	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	rtn = (char*)malloc(sizeof(char) * (len + 1));
	while (i < len)
		rtn[i++] = *s++;
	rtn[i] = '\0';
	return (rtn);
}

char	**ft_split(const char *s, char c)
{
	int		cnt;
	int		i;
	char	**rtn;
	char	*tmp;

	if (s == '\0')
		return (0);
	tmp = (char *)s;
	cnt = count_delimiter(tmp, c);
	rtn = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (rtn == '\0')
		return (0);
	i = 0;
	while (i < cnt)
	{
		rtn[i] = put_word(tmp + order_word(tmp, c, i), c);
//		if (rtn[i] == 0)
//			return (free_func());
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}
