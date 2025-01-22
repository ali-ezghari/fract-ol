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