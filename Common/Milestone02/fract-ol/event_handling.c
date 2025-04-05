
#include "fractol.h"

int	key_press(int button, t_fractol *fract)
{
	if (button == 65363)
		fract->trans.x -= 50 / fract->zoom;
	else if (button == 65361)
		fract->trans.x += 50 / fract->zoom;
	else if (button == 65362)
		fract->trans.y += 50 / fract->zoom;
	else if (button == 65364)
		fract->trans.y -= 50 / fract->zoom;
	else if (button == 99)
		fract->color++;
	else if (button == 114)
		fract_centring(fract);
	else if (button == 65307)
		clean_fract(fract);
	rendering(fract);
	return (0);
}

int	mouse_handling(int button, int x, int y, t_fractol *fract)
{
	double	zoom_factor;

	zoom_factor = 1.1;
	if (button == 5)
	{
		fract->trans.x = (x / fract->zoom + fract->trans.x)
			- x / (fract->zoom * zoom_factor);
		fract->trans.y = (y / fract->zoom + fract->trans.y)
			- y / (fract->zoom * zoom_factor);
		fract->zoom *= zoom_factor;
	}
	if (button == 4)
	{
		fract->trans.x = (x / fract->zoom + fract->trans.x)
			- x / (fract->zoom / zoom_factor);
		fract->trans.y = (y / fract->zoom + fract->trans.y)
			- y / (fract->zoom / zoom_factor);
		fract->zoom /= zoom_factor;
	}
	rendering(fract);
	return (0);
}

int	clean_fract(t_fractol *fract)
{
	if (fract->image.img)
		mlx_destroy_image(fract->mlx, fract->image.img);
	if (fract->mlx_win)
		mlx_destroy_window(fract->mlx, fract->mlx_win);
	mlx_destroy_display(fract->mlx);
	free(fract->mlx);
	exit(0);
	return (0);
}
