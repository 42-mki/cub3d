/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeyoo <9hrack@gmail.com>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:49:25 by hyeyoo            #+#    #+#             */
/*   Updated: 2020/02/26 23:46:57 by hyeyoo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	alloc_size;

	alloc_size = size * nmemb;
	if (size != alloc_size / nmemb)
		return (NULL);
	if ((ptr = malloc(alloc_size)) == NULL)
		return (NULL);
	memset(ptr, 0, alloc_size);
	return (ptr);
}
