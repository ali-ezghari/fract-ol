#include "fractol_bonus.h"

int	handle_key(int keycode, t_fractal *fractal)
{
	if (keycode == ESC_KEY)
		free_close(fractal);
	else if (keycode == LEFT_ARROW)
		fractal->shift_x -= fractal->scale * 0.1;
	else if (keycode == RIGHT_ARROW)
		fractal->shift_x += fractal->scale * 0.1;
	else if (keycode == DOWN_ARROW)
		fractal->shift_y -= fractal->scale * 0.1;
	else if (keycode == UP_ARROW)
		fractal->shift_y += fractal->scale * 0.1;
	else if (keycode == M_KEY)
		fractal->iterations += 10;
	else if (keycode == P_KEY && fractal->iterations > 10)
		fractal->iterations -= 10;
	else if (keycode == O_KEY)
		fractal->scale *= 1.1;
	else if (keycode == Z_KEY)
		fractal->scale *= 0.9;
	draw_fractal(fractal);
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractal *fractal)
{
	if (button == 5)
		mouse_zoom(fractal, x, y, 0.9);
	else if (button == 4)
		mouse_zoom(fractal, x, y, 1.1);
	draw_fractal(fractal);
	return (0);
}
