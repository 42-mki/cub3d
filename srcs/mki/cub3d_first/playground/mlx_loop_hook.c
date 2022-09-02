#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

/*
** I added stdlib.h for exit()
** key 13 == w
** key 0 == a
** key 1 == s
** key 2 == d
** key 53 == esc
**
**
*/


typedef struct	s_var
{
	int			x;
	int			y;
	int			key_flag[256];
}				t_var;

void	s_var_init(t_var *sv)
{
	int	i;

	i = 256;
	while (i)
		sv->key_flag[--i] = 0;
	sv->x = 0;
	sv->y = 0;
}

int		ft_key_release(int key, t_var *sv)
{
	sv->key_flag[key] = 0;
	return (0);
}

int		ft_key_press(int key, t_var *sv)
{
	sv->key_flag[key] = 1;
	return (0);
}

int		ft_hook(t_var *sv)
{
	if (sv->key_flag[0])
		sv->x--;
	if (sv->key_flag[2])
		sv->x++;
	if (sv->key_flag[1])
		sv->y++;
	if (sv->key_flag[13])
		sv->y--;
	if (sv->key_flag[53])
		exit(0);
	printf("x: %d y: %d\n", sv->x, sv->y);
	return (0);
}

int		main(void)
{
	void	*mlx;
	void	*win;
	t_var	sv;
	
	s_var_init(&sv);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 800, 600, "doing great");
	mlx_hook(win, 2, 0, &ft_key_press, &sv);
	mlx_hook(win, 3, 0, &ft_key_release, &sv);
	mlx_loop_hook(mlx, &ft_hook, &sv);
	mlx_loop(mlx);
	return (0);
}