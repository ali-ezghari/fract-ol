#include "fractol.h"

#include "fractol.h"

int parsing(int ac, char **av, t_fractal *fractal)
{
    if (ac == 2 && !ft_strncmp(av[1], "mandelbrot", 10))
        fractal->id = MANDEL;
    else if ((ac == 2 || ac == 4) && !ft_strncmp(av[1], "julia", 5))
    {
        fractal->id = JULIA;
        if (ac == 4)
        {
            fractal->julia_x = atodbl(av[2]);
            fractal->julia_y = atodbl(av[3]);
        }
        else if (ac == 2)
        {
            fractal->julia_x = -0.74543;
            fractal->julia_y = 0.11301;
        }
        else
            return (-1);
    }
    else if (!ft_strncmp(av[1], "burning_ship", 12))
        fractal->id = SHIP;
    return 0;
}

int main(int ac, char **av)
{
    t_fractal fractal;

    if (ac == 2 || ac == 4)
    {
        if ((parsing(ac, av, &fractal) == -1) || (fractal.id != JULIA && fractal.id != SHIP && fractal.id != MANDEL))
        {
            usage();
            exit(EXIT_SUCCESS);
        }
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
