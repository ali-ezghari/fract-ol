#include "fractol.h"

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
	ft_putstr_fd(" +------------------ Need some help?  ---------------------+\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | Usage: ./fractol [mandelbrot / julia / burning_ship]    |\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | e.g: ./fractol mandelbrot                               |\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" |----------------------- KEYBOARD ------------------------|\n", 1);
	ft_putstr_fd(" |                                                         |\n", 1);
	ft_putstr_fd(" | Press ESC to close the window                           |\n", 1);
	ft_putstr_fd(" | Press Z to zoom into the fractal		                 |\n", 1);
	ft_putstr_fd(" | Use mouse scroll to zoom in and out of the fractal      |\n", 1);
	ft_putstr_fd(" | Press the arrow keys to change the viewpoint            |\n", 1);
	ft_putstr_fd(" +---------------------------------------------------------+\n", 1);
	ft_putstr_fd("\e[0m\n", 1);
	exit(EXIT_SUCCESS);
}