/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:42:38 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:45:00 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libbmp.h"

t_uint	bytes_to_number(t_uchar *str, t_uint n)
{
	t_uint ret;

	ret = 0;
	if (n == 4)
		ret = (str[3] << 24) | (str[2] << 16) | (str[1] << 8) | str[0];
	if (n == 2)
		ret = (str[1] << 8) | str[0];
	return (ret);
}

void	number_to_bytes(t_uint nb, t_uchar *buffer, t_uint len)
{
	int shift;
	int i;

	i = len - 1;
	shift = (len != 1) ? (len - 1) * 8 : 0;
	while (shift != 0)
	{
		buffer[i] = (nb >> shift) & 0xFF;
		shift -= 8;
		i--;
	}
	buffer[i] = nb & 0xFF;
}

void	free2d(unsigned char ***str)
{
	int i;

	i = 0;
	while ((*str)[i] != 0)
	{
		free((*str)[i]);
		i++;
	}
	free((*str)[i]);
	free(*str);
	*str = NULL;
}
