typedef struct	s_vec
{
	double	x;
	double	y;
}				t_vec;

t_vec	vec_new(double x, double y)
{
	t_vec	result;

	result.x = x;
	result.y = y;
	return (result);
}

t_vec	vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	return (a);
}

t_vec	vec_sub(t_vec a, t_vec b)
{
	a.x -= b.x;
	a.y -= b.y;
	return (a);
}

t_vec	vec_mul(t_vec a, double b)
{
	a.x *= b;
	a.y *= b;
	return (a);
}

int		main(void)
{

}