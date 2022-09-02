/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sujeong <sujeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/19 08:44:04 by sujeong           #+#    #+#             */
/*   Updated: 2020/11/19 08:45:13 by sujeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char		*tab;

	if (!(tab = (char*)malloc(size * count)))
		return (NULL);
	ft_bzero(tab, count * size);
	return (tab);
}
