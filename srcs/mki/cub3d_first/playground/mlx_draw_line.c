#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
#define SIZE			64		
#define ROWS			10
#define	COLS			10
#define WIDTH			SIZE * ROWS
#define HEIGHT			SIZE * COLS	
#define TITLE			"draw_line"

typedef struct	s_img
{
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
}				t_mlx;

void	ft_draw_line(int *img)
{
	int		cnt_rows;
	int		cnt;

	cnt = 0;
	while (cnt < WIDTH * HEIGHT)
	{
		img[cnt] = 0xFF0000;
		cnt += SIZE;
	}
	cnt_rows = -1; 
	while (++cnt_rows < ROWS)
	{
		cnt = -1;
		while (++cnt < WIDTH)
			img[cnt + cnt_rows * WIDTH * SIZE] = 0xFF0000;
	}
}

int		main(void)
{
	t_mlx	mlx;
	t_img	img;
	
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);
	img.img_data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	ft_draw_line(img.img_data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}