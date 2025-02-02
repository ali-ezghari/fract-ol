#include "fractol.h"

int	parsing(int ac, char **av, t_fractal *fractal)
{
	if (ac == 2 && compare(av[1], "mandelbrot") == 0)
		fractal->id = MANDEL;
	else if ((ac == 2 || ac == 4) && compare(av[1], "julia") == 0)
	{
		fractal->id = JULIA;
		if (ac == 4)
		{
			fractal->julia_x = atodbl(av[2]);
			fractal->julia_y = atodbl(av[3]);
			if (coord_check(fractal) == -1)
				f_format_err();
		}
		else if (ac == 2)
		{
			fractal->julia_x = -0.74543;
			fractal->julia_y = 0.11301;
		}
		else
			return (-1);
	}
	else
		return (-1);
	return (0);
}

int	main(int ac, char **av)
{
	t_fractal	fractal;

	if (parsing(ac, av, &fractal) == -1)
	{
		usage();
	}
	fractal.name = av[1];
	fractal_init(&fractal);
	draw_fractal(&fractal);
	mlx_loop(fractal.mlx_connection);
	return (0);
}
