/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42seoul.fr>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 11:29:18 by mki               #+#    #+#             */
/*   Updated: 2021/03/10 17:57:29 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	save_check(char *s, int *flag)
{
	int		ret;

	ret = 0;
	if (ft_strlen(s) != 6)
		return (1);
	ret = ft_strncmp(s, "--save", 6);
	if (!ret)
		*flag = 1;
	return (ret);
}

static int	suffix_check(char *s)
{
	char	*cub;
	int		len;

	len = ft_strlen(s);
	if (len < 5)
		return (1);
	cub = s + len - 4;
	return (ft_strncmp(cub, ".cub", 4));
}

int			main(int argc, char *argv[])
{
	t_data	d;

	d.par.file = argv[1];
	d.bmp.save_flag = 0;
	if (argc == 2 || argc == 3)
	{
		if (suffix_check(argv[1]))
			write(1, "Error\n", 6);
		else if (argc == 3 && save_check(argv[2], &d.bmp.save_flag))
			write(1, "Error\n", 6);
		else if (parsing(&d))
			write(1, "Error\n", 6);
		else if (cub3d(&d))
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
	return (0);
}
