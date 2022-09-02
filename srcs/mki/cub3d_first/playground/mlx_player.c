#include "../mlx/mlx.h"

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
}				t_mlx;

int		main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, 5, 5);
	mlx.img_data = (int *)mlx_get_data_addr(mlx.img_ptr, &mlx.bpp, &mlx.size_l, &mlx.endian);
	mlx.player = -1;
	while (++mlx.player < 25)
		mlx.img_data[mlx.player] = 0xFF0000;
	mlx.img_data[0] = 0xFF00FF;
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, WIDTH / 2, HEIGHT / 2);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}