#include "../mlx/mlx.h"
#include <stdlib.h>

typedef struct	s_var
{
	void		*mlx;
	void		*win;
	void		*img;
	int			x;
	int			y;
	int			key_flag[300];
}				t_var;

void	ft_arr_init(int *arr)
{
	int i;

	i = 0;
	while (i < 300)
		arr[i++] = 0;
}

void	s_var_init(t_var *sv)
{
	sv->x = 0;
	sv->y = 0;
	ft_arr_init(sv->key_flag);
}

int		ft_key_press(int key, t_var *sv)
{
	sv->key_flag[key] = 1;
	return (0);
}

int		ft_key_release(int key, t_var *sv)
{
	sv->key_flag[key] = 0;
	return (0);
}

int		ft_map(t_var *sv)
{
	if (sv->key_flag[0])
		sv->x -= 10;
	if (sv->key_flag[2])
		sv->x += 10;
	if (sv->key_flag[13])
		sv->y -= 10;
	if (sv->key_flag[1])
		sv->y += 10;
	if (sv->key_flag[53])
		exit(0);
	// mlx_clear_window(sv->mlx, sv->win);
	mlx_put_image_to_window(sv->mlx, sv->win, sv->img, sv->x, sv->y);
	return (0);
}

int		main(void)
{
	int		img_w;
	int		img_h;
	t_var	sv;

	s_var_init(&sv);
	sv.mlx = mlx_init();
	sv.win = mlx_new_window(sv.mlx, 800, 600, "cub3D");
	sv.img = mlx_xpm_file_to_image(sv.mlx ,"../textures/wall_s.xpm", &img_w, &img_h);
	mlx_hook(sv.win, 2, 0, &ft_key_press, &sv);
	mlx_hook(sv.win, 3, 0, &ft_key_release, &sv);
	mlx_loop_hook(sv.mlx, &ft_map, &sv);
	mlx_loop(sv.mlx);
	return (0);
}
