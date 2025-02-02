#include "fractol.h"

int	coord_check(t_fractal *fractal)
{
	if ((fractal->julia_x > 2 || fractal->julia_x < -2)
		|| (fractal->julia_y > 2 || fractal->julia_y < -2))
		return (-1);
	else
		return (0);
}

void	put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int	offset;

	offset = fractal->img.line_length * y;
	offset += (x * (fractal->img.bits_per_pixel / 8));
	*((unsigned int *)(offset + fractal->img.img_pixel_ptr)) = color;
}

int	free_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

void	mem_err(void)
{
	ft_putstr_fd("Error: Memory allocation failed\n", 2);
	exit(EXIT_FAILURE);
}

void	usage(void)
{
	ft_putstr_fd("\n\e[36m", 1);
	ft_putstr_fd(" +-------------------- Need some help?  -------------+\n", 1);
	ft_putstr_fd(" |                                                   |\n", 1);
	ft_putstr_fd(" | Usage: ./fractol [mandelbrot / julia x y ]        |\n", 1);
	ft_putstr_fd(" | e.g: ./fractol mandelbrot                         |\n", 1);
	ft_putstr_fd(" |    : ./fractol julia -0.74543 0.11301             |\n", 1);
	ft_putstr_fd(" |----------------------- KEYBOARD ------------------|\n", 1);
	ft_putstr_fd(" |                                                   |\n", 1);
	ft_putstr_fd(" | Press ESC to close the window                     |\n", 1);
	ft_putstr_fd(" | Use mouse scroll to zoom in and out of the fractal|\n", 1);
	ft_putstr_fd(" |                                                   |\n", 1);
	ft_putstr_fd(" +---------------------------------------------------+\n", 1);
	ft_putstr_fd("\e[0m\n", 1);
	exit(EXIT_SUCCESS);
}
