#include "fractol.h"

int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
		free_close(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	x += 1;
	y += 1;
	if (button == 5)
		fractal->scale *= 0.9;
	else if (button == 4)
		fractal->scale *= 1.1;
	draw_fractal(fractal);
	return (0);
}
