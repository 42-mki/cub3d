/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bitmap.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mki <mki@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/22 21:39:26 by mki               #+#    #+#             */
/*   Updated: 2021/02/22 22:25:49 by mki              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../mlx/mlx.h"
#include <fcntl.h>
#include <unistd.h>

typedef struct s_img
{
	void		*ptr;
	int			*data;
	int			width;
	int			height;


	int			size_l;
	int			bpp;
	int			endian;
}				t_img;

typedef struct	s_bmp
{
	int			i;
}				t_bmp;

void	save(int *data)
{
	int		fd;

	fd = open("save.bmp", O_WRONLY | O_TRUNC | O_APPEND | O_CREAT | O_EXCL
	, S_IRWXU | S_IRWXG | S_IRWXO);
	bitmap_file_header(fd);
	bitmap__header(fd);
	close(fd);
}

int main()
{
		void	*mlx;
		void	*win;
		t_img	img;
		int		count_h;
		int		count_w;

		mlx = mlx_init();
		win = mlx_new_window(mlx, 500, 500, "my_mlx");
		img.ptr = mlx_xpm_file_to_image(mlx, "../textures/wall_s.xpm", &img.width, &img.height);
		img.data = (int *)mlx_get_data_addr(img.ptr, &img.bpp, &img.size_l, &img.endian);

		count_h = -1;
		while (++count_h < img.height)
		{
			count_w = -1;
			while (++count_w < img.width / 2)
			{
				if (count_w % 2)
					img.data[count_h * img.width + count_w] = 0xFFFFFF;
				else
					img.data[count_h * img.width + count_w] = 0xFF0000;
			}
		}
		save(img.data);
		mlx_put_image_to_window(mlx, win, img.ptr, 50, 50);
		mlx_loop(mlx);
		return (0);
}
