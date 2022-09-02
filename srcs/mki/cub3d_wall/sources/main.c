/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:29:18 by mki               #+#    #+#             */
/*   Updated: 2021/02/04 15:48:42 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	suffix_check(char *s)
{
	char	*cub;
	int		len;

	len = ft_strlen(s);
	cub = s + len - 4;
	return (ft_strncmp(cub, ".cub", 4));
}

int			main(int argc, char *argv[])
{
	t_data	d;

	if (argc == 2)
	{
		if (suffix_check(argv[1]))
			write(1, "Error\n", 6);
		else if (cub_check(&d))
			write(1, "Error\n", 6);
		else
			if(cub3d(&d))
				return (0);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
