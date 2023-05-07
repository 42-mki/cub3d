#include "../mlx/mlx.h"

#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS	2;
#define X_EVENT_KEY_RELEASE	3;
#define X_EVENT_EXIT		17;

#define KEY_A				0;
#define KEY_S				1;
#define KEY_D				2;
#define KEY_W				13;

#define SIZE				64		
#define ROWS				10
#define	COLS				10
#define WIDTH				SIZE * ROWS
#define HEIGHT				SIZE * COLS	
#define TITLE				"draw_line"

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
	int			key_flag[256];
	int			player;
	void		*img_ptr;
	int			*img_data;
	int			bpp;
	int			size_l;
	int			endian;
	int			pos_x;
	int			pos_y;			
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

int		ft_press(int key, t_mlx *mlx)
{
	mlx->key_flag[key] = 1;
	return (0);
}

int		ft_release(int key, t_mlx *mlx)
{
	mlx->key_flag[key] = 0;
	return (0);
}

int		ft_moving(t_mlx *player)
{
	if (player->key_flag[0])
		player->pos_x -= 5;
	if (player->key_flag[1])
		player->pos_y += 5;
	if (player->key_flag[2])
		player->pos_x += 5;
	if (player->key_flag[13])
		player->pos_y -= 5;
	if (player->key_flag[53])
		exit(0);
	mlx_clear_window(player->mlx_ptr, player->win_ptr);
	mlx_put_image_to_window(player->mlx_ptr, player->win_ptr, player->img_ptr, player->pos_x, player->pos_y);
	return (0);
}

int		main(void)
{
	t_mlx		mlx;
	t_img		img;
	int			i;

	i = 256;
	while (--i)
		mlx.key_flag[i] = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIDTH, HEIGHT);

	img.img_data = (int *)mlx_get_data_addr(img.img_ptr, &img.bpp, &img.size_l, &img.endian);
	ft_draw_line(img.img_data);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, img.img_ptr, 0, 0);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 5, 5);

	mlx.img_data = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	mlx.player = -1;
	while (++mlx.player < 25)
		mlx.img_data[mlx.player] = 0xFF0000;
	mlx.pos_x = WIDTH / 2;
	mlx.pos_y = HEIGHT / 2;
	mlx_hook(mlx.win_ptr, 2, 0, &ft_press, &mlx);
	mlx_hook(mlx.win_ptr, 3, 0, &ft_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_moving, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
