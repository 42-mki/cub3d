/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/26 03:06:49 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 04:00:35 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	size;
	char			*rtn;

	if (s == 0)
		return (0);
	size = ft_strlen(s);
	if ((rtn = (char *)malloc(sizeof(char) * (size + 1))) == 0)
		return (0);
	i = 0;
	while (s[i] != 0)
	{
		rtn[i] = f(i, s[i]);
		i++;
	}
	rtn[i] = 0;
	return (rtn);
}

/*
** 함수 기능 설명
** s를 받아서, 각각의 f함수에다가 적용
** 예를 들어 s가 abcde 이고 plus가 들어온 값에 1씩 더해서 반환하는 함수라면 -
** char plus(unsigned int n, char c)
** {
**	char tmp;
**	tmp = c + 2;
**	return (tmp);
** }
** ft_strmapi(*s, plus(i,s[i]));
** cedfg 가 반환
*/
