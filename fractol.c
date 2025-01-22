#include "fractol.h"

int main(int ac, char **av)
{
    t_fractal fractal;

    if ((ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10)) || (ac == 2 && !ft_strncmp(av[1], "julia", 5)))
    {
        fractal.name = av[1];
        fractal_init(&fractal);
        draw_fractal(&fractal);
        mlx_loop(fractal.mlx_connection);
    }
    else
    {
        usage();
    }
    return 0;
}
