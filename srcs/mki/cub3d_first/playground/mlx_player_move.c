#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define		WIDTH	800
#define		HEIGHT	600
#define		TITLE	"cub3D"

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		*img_data;
	int		bpp;
	int		size_l;
	int		endian;
	int		player;
	int		pos_x;
	int		pos_y;
	int		key_flag[256];
}				t_mlx;

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

int		ft_moving(t_mlx *mlx)
{
	if (mlx->key_flag[0])
		mlx->pos_x -= 5;
	if (mlx->key_flag[1])
		mlx->pos_y += 5;
	if (mlx->key_flag[2])
		mlx->pos_x += 5;
	if (mlx->key_flag[13])
		mlx->pos_y -= 5;
	if (mlx->key_flag[53])
		exit(0);
	mlx_clear_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, mlx->pos_x, mlx->pos_y);
	return (0);
}

int		main(void)
{
	t_mlx	mlx;
	int		i;

	i = 256;
	while (--i)
		mlx.key_flag[i] = 0;
	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 5, 5);
	mlx.img_data = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	mlx.player = -1;
	while (++mlx.player < 25)
		mlx.img_data[mlx.player] = 0xFF0000;
	mlx.img_data[0] = 0xFF00FF;
	mlx.pos_x = WIDTH / 2;
	mlx.pos_y = HEIGHT / 2;
	mlx_hook(mlx.win_ptr, 2, 0, &ft_press, &mlx);
	mlx_hook(mlx.win_ptr, 3, 0, &ft_release, &mlx);
	mlx_loop_hook(mlx.mlx_ptr, &ft_moving, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}