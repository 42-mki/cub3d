#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_var
{
	int			x;
	int			y;
}				t_var;

void	s_var_init(t_var *sv)
{
	sv->x = 0;
	sv->y = 0;
}

int		ft_test(int key, t_var *sv)
{
	if (key == 2)
		sv->x++;
	else if (key == 0)
		sv->x--;
	else if (key == 13)
		sv->y--;
	else if (key == 1)
		sv->y++;
	else if (key == 53)
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
	win = mlx_new_window(mlx, 500, 500, "hello");
	mlx_hook(win, 2, 0, ft_test, &sv);
	mlx_hook(win, 2, 0, ft_test, &sv);
	mlx_loop(mlx);
	return (0);
}
