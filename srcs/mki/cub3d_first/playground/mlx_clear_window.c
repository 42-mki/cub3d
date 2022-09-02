#include "../mlx/mlx.h"
#include <stdio.h>

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	int		img_x;
	int		img_y;
}				t_mlx;

int		ft_clear(int key, t_mlx mlx)
{
	if (key == 0)
	{
		mlx_clear_window(mlx.mlx_ptr, mlx.win_ptr);
		mlx_destroy_image(mlx.mlx_ptr, mlx.img_ptr);
		printf("hello\n");
	}
	return (0);
}

int		main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, 500, 500, "hello");
	mlx.img_ptr = mlx_xpm_file_to_image(mlx.mlx_ptr, "../textures/wall_w.xpm", &mlx.img_x, &mlx.img_y);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 64, 64);
	mlx_key_hook(mlx.win_ptr, &ft_clear, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}