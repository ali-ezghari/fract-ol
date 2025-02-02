#include "fractol_bonus.h"

double	map(double coord, double range, double min, double max)
{
	return (coord / range * (max - min) + min);
}

t_complex	calc_mandel(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	result.x += c.x;
	result.y += c.y;
	return (result);
}

t_complex	calc_julia(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = 2 * z.x * z.y;
	result.x += c.x;
	result.y += c.y;
	return (result);
}

t_complex	calc_ship(t_complex z, t_complex c)
{
	t_complex	result;

	result.x = (z.x * z.x) - (z.y * z.y);
	result.y = -2 * fabs(z.x) * fabs(z.y);
	result.x += c.x;
	result.y += c.y;
	return (result);
}

void	mouse_zoom(t_fractal *fractal, int mouse_x, int mouse_y, double zoom)
{
	double	mouse_re;
	double	mouse_im;

	mouse_re = map(mouse_x, WIDTH, -fractal->scale,
			fractal->scale) + fractal->shift_x;
	mouse_im = map(mouse_y, HEIGHT, fractal->scale,
			-fractal->scale) + fractal->shift_y;
	fractal->scale *= zoom;
	fractal->shift_x = mouse_re - map(mouse_x, WIDTH,
			-fractal->scale, fractal->scale);
	fractal->shift_y = mouse_im - map(mouse_y, HEIGHT,
			fractal->scale, -fractal->scale);
}
