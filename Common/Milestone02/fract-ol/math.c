
#include "fractol.h"

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	sum;

	sum.x = a.x + b.x;
	sum.y = a.y + b.y;
	return (sum);
}

double	abs_val(double x)
{
	if (x < 0)
		x = -x;
	return (x);
}

t_complex	square_complex(t_complex z)
{
	t_complex	res;

	res.x = (z.x * z.x) - (z.y * z.y);
	res.y = 2 * z.x * z.y;
	return (res);
}

double	mod(t_complex z)
{
	double	mod;

	mod = z.x * z.x + z.y * z.y;
	return (mod);
}
