#include <stdio.h>
#include "../mlx/mlx.h"

# define WIN_W 800
# define WIN_H 600

# define IMG_W 400
# define IMG_H 300

typedef struct	s_img
{
	void		*img_ptr;
	int			*data;
	int			size_l;
	int			bpp;
	int			endian;
	int			cnt_w;
	int			cnt_h;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win;
}				t_mlx;

int		main(void)
{
	t_mlx	mlx;
	t_img	img;
	
	mlx.mlx_ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_W, WIN_H, "cub3D");
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, IMG_W, IMG_H);
	img.data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	img.cnt_h = -1;
	while (++img.cnt_h < IMG_H)
	{
		img.cnt_w = -1;
		while (++img.cnt_w < IMG_W)
		{
			if (img.cnt_w % 100)
				img.data[img.cnt_h * IMG_H + img.cnt_w] = 0x000000;
			else
				img.data[img.cnt_h * IMG_H + img.cnt_w] = 0xFFFFFF;
		}
	}
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
}