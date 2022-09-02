#include "../mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

#define	KEY_ESC				53
#define	X_EVENT_EXIT		17
#define X_EVENT_KEY_PRESS	2
#define WIDTH				800
#define HEIGHT				600
#define TITLE				"draw_line"	

typedef	struct	s_img
{
	void		*img_ptr;
	int			bpp;
	int			size_l;
	int			endian;
}				t_img;

typedef struct	s_mlx
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		img;
}				t_mlx;

int		main(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = mlx_init();
	mlx.win_ptr = mlx_new_window(mlx.mlx_ptr, WIDTH, HEIGHT, TITLE);
	mlx_pixel_put(mlx.mlx_ptr, mlx.win_ptr, WIDTH / 2, HEIGHT / 2, 0xFF0000);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}