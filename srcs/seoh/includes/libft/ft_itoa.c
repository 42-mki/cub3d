/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seoh <seoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 19:43:03 by seoh              #+#    #+#             */
/*   Updated: 2020/04/26 04:29:29 by seoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		digitlen(long long n)
{
	int i;

	i = 0;
	if (n < 0)
		n = n * -1;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	return (i + 1);
}

char	*ft_itoa(int n)
{
	char			*rtn;
	int				len;
	unsigned int	tmp;

	len = digitlen(n);
	if (n < 0)
		tmp = n * -1;
	if (n < 0)
		len++;
	else
		tmp = n;
	if ((rtn = (char *)malloc(sizeof(char) * (len + 1))) == 0)
		return (0);
	rtn[len] = 0;
	if (n < 0)
		rtn[0] = '-';
	rtn[--len] = '0' + (tmp % 10);
	while (tmp > 0)
	{
		rtn[len--] = tmp % 10 + '0';
		tmp = tmp / 10;
	}
	return (rtn);
}
