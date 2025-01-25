#include "fractol.h"

double map(double coord, double range, double min, double max)
{
    return (coord) / (range) * (max - min) + min;
}
t_complex calc_mandel(t_complex z, t_complex c)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    result.x += c.x;
    result.y += c.y;
    return result;
}
t_complex calc_julia(t_complex z, t_complex c)
{
    t_complex result;

    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    result.x += c.x;
    result.y += c.y;
    return result;
}
t_complex calc_ship(t_complex z, t_complex c)
{
    t_complex result;

    z.y = fabs(z.y);
    result.x = z.x * z.x - z.y * z.y;
    result.y = -2 * fabs(z.x) * z.y;
    result.x += c.x;
    result.y += c.y;
    return result;
}
void mouse_zoom(t_fractal *fractal, int mouse_x, int mouse_y, double zoom_factor)
{
    // Convert mouse pixel coordinates to complex plane coordinates
    double mouse_real;
    double mouse_imag;

    mouse_real = map(mouse_x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    mouse_imag = map(mouse_y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y;
    // Adjust scale and shift for zoom
    fractal->scale *= zoom_factor;
    fractal->shift_x = mouse_real - map(mouse_x, WIDTH, -fractal->scale, fractal->scale);
    fractal->shift_y = mouse_imag - map(mouse_y, HEIGHT, fractal->scale, -fractal->scale);
}