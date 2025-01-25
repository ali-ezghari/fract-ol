#include "fractol.h"

double atodbl(char *str)
{
	int sign;
	double res;
	double decimal;

	decimal = 0.1;
	res = 0;
	sign = 1;
	while (*str == 32 || (*str >= 9 && *str <= 13))
		++str;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		++str;
	}
	while (*str >= '0' && *str <= '9')
		res = res * 10 + *str++ - '0';
	if (*str == '.')
		++str;
	while (*str >= '0' && *str <= '9')
	{
		res += (*str++ - '0') * decimal;
		decimal /= 10;
	}
	return (res * sign);
}

void put_color_to_pixel(t_fractal *fractal, int x, int y, int color)
{
	int offset;

	offset = (fractal->img.line_length * y) + (x * (fractal->img.bits_per_pixel / 8));
	*((unsigned int *)(offset + fractal->img.img_pixel_ptr)) = color; // color the pixel
}

int free_close(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
	return (0);
}

void mem_err()
{

	perror("Error");
	exit(EXIT_FAILURE);
}
void usage()
{
	ft_putstr_fd("\n\e[36m", 1);
	ft_putstr_fd(" +-------------------- Need some help?  ---------------------+\n", 1);
	ft_putstr_fd(" |                                                           |\n", 1);
	ft_putstr_fd(" | Usage: ./fractol [mandelbrot / julia x y / burning_ship]  |\n", 1);
	ft_putstr_fd(" |                                                           |\n", 1);
	ft_putstr_fd(" | e.g: ./fractol mandelbrot                                 |\n", 1);
	ft_putstr_fd(" |    : ./fractol julia -0.74543 0.11301                     |\n", 1);
	ft_putstr_fd(" |----------------------- KEYBOARD --------------------------|\n", 1);
	ft_putstr_fd(" |                                                           |\n", 1);
	ft_putstr_fd(" | Press ESC to close the window                             |\n", 1);
	ft_putstr_fd(" | Press Z to zoom into the fractal                          |\n", 1);
	ft_putstr_fd(" | Use mouse scroll to zoom in and out of the fractal        |\n", 1);
	ft_putstr_fd(" | Press the arrow keys to change the viewpoint              |\n", 1);
	ft_putstr_fd(" |                                                           |\n", 1);
	ft_putstr_fd(" +-----------------------------------------------------------+\n", 1);
	ft_putstr_fd("\e[0m\n", 1);
	exit(EXIT_SUCCESS);
}