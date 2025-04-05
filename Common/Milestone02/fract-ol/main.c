
#include "fractol.h"

void	init_fract(t_fractol *fract, char *name)
{
	fract->name = name;
	fract->mlx = mlx_init();
	if (!fract->mlx)
		exit(1);
	fract->mlx_win = mlx_new_window(fract->mlx, SIZE, SIZE, fract->name);
	if (!fract->mlx_win)
		exit(1);
	fract->image.img = mlx_new_image(fract->mlx, SIZE, SIZE);
	if (!fract->image.img)
	{
		mlx_destroy_window(fract->mlx, fract->mlx_win);
		exit(1);
	}
	fract->image.addr = mlx_get_data_addr(fract->image.img,
			&(fract->image.bits_per_pixel), &(fract->image.line_length),
			&(fract->image.endian));
	fract_centring(fract);
	mlx_key_hook(fract->mlx_win, key_press, fract);
	mlx_mouse_hook(fract->mlx_win, mouse_handling, fract);
	mlx_hook(fract->mlx_win, 17, 0L, clean_fract, fract);
}

void	fract_centring(t_fractol *fract)
{
	fract->precision = 100;
	fract->color = 1;
	fract->zoom = SIZE / 4;
	fract->trans.x = -SIZE / (2.0 * fract->zoom);
	fract->trans.y = -SIZE / (2.0 * fract->zoom);
}

int	main(int ac, char **av)
{
	t_fractol	fract;

	if (SIZE == 0)
		return (1);
	if ((ac == 2 && !ft_strcmp(av[1], "mandelbrot"))
		|| (ac == 4 && !ft_strcmp(av[1], "julia")
			&& chec_julia(av[2]) && chec_julia(av[3]))
		|| (ac == 2 && !ft_strcmp(av[1], "julia")))
	{
		init_fract(&fract, av[1]);
		if (!ft_strcmp(fract.name, "julia") && ac == 4)
		{
			fract.julia.x = ft_atod(av[2]);
			fract.julia.y = ft_atod(av[3]);
		}
		else if (!ft_strcmp(fract.name, "julia") && ac == 2)
		{
			fract.julia.x = 0.365;
			fract.julia.y = 0.365;
		}
		rendering(&fract);
		mlx_loop(fract.mlx);
		clean_fract(&fract);
	}
	ft_strput("Availible fractol : mandelbrot and julia with 2 or 4 arg\n");
}
