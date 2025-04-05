
#include "fractol.h"

void	plot_julia(t_fractol *fract, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	c.x = fract->julia.x;
	c.y = fract->julia.y;
	z.x = x / fract->zoom + fract->trans.x;
	z.y = y / fract->zoom + fract->trans.y;
	iter = -1;
	while (++iter < fract->precision)
	{
		z = add_complex(square_complex(z), c);
		if (mod(z) >= __DBL_MAX__)
			break ;
	}
	if (iter == fract->precision)
		my_mlx_pixel_put(&(fract->image), x, y, 0x000000);
	else
		my_mlx_pixel_put(&(fract->image), x, y, color(iter, fract));
}

void	plot_man(t_fractol *fract, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			iter;

	z.x = 0;
	z.y = 0;
	c.x = x / fract->zoom + fract->trans.x;
	c.y = y / fract->zoom + fract->trans.y;
	iter = -1;
	while (++iter < fract->precision)
	{
		z = add_complex(square_complex(z), c);
		if (mod(z) >= __DBL_MAX__)
			break ;
	}
	if (iter == fract->precision)
		my_mlx_pixel_put(&(fract->image), x, y, 0x000000);
	else
		my_mlx_pixel_put(&(fract->image), x, y, color(iter, fract));
}

void	rendering(t_fractol *fract)
{
	int	x;
	int	y;

	x = -1;
	while (++x < SIZE)
	{
		y = -1;
		while (++y < SIZE)
		{
			if (!ft_strcmp(fract->name, "mandelbrot"))
				plot_man(fract, x, y);
			else if (!ft_strcmp(fract->name, "julia"))
				plot_julia(fract, x, y);
		}
	}
	mlx_put_image_to_window(fract->mlx, fract->mlx_win, fract->image.img, 0, 0);
}
