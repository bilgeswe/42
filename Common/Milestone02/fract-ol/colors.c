
#include "fractol.h"

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	color(int iter, t_fractol *fract)
{
	int	color_tab[22];

	color_tab[0] = 0x008080;
	color_tab[1] = 0xFF7F50;
	color_tab[2] = 0x6A5ACD;
	color_tab[3] = 0xFFD700;
	color_tab[4] = 0xDA70D6;
	color_tab[5] = 0x87CEEB;
	color_tab[6] = 0x32CD32;
	color_tab[7] = 0xFA8072;
	color_tab[8] = 0xE6E6FA;
	color_tab[9] = 0xFF8C00;
	color_tab[10] = 0xFF69B4;
	color_tab[11] = 0x1E90FF;
	color_tab[12] = 0x00FA9A;
	color_tab[13] = 0xFFDAB9;
	color_tab[14] = 0x4682B4;
	color_tab[15] = 0xFF6347;
	color_tab[16] = 0x00CED1;
	color_tab[17] = 0x8A2BE2;
	color_tab[18] = 0x7B68EE;
	color_tab[19] = 0x228B22;
	color_tab[20] = 0xFF1493;
	color_tab[21] = 0x40E0D0;
	return (color_tab[(fract->color + iter % 6) % 22] / iter);
}
