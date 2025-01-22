#include "fractol.h"

static void data_init(t_fractal *fractal)
{
    fractal->shift_x = 0.0;
    fractal->shift_y = 0.0;
    fractal->scale = 2;
}
static void events_init(t_fractal *fractal)
{
    mlx_hook(fractal->mlx_window,
             KeyPress,
             KeyPressMask,
             handle_key,
             fractal);
    mlx_hook(fractal->mlx_window, 17, 0, free_close, fractal);
    mlx_mouse_hook(fractal->mlx_window, mouse_hook, fractal);
}

void fractal_init(t_fractal *fractal)
{
    fractal->mlx_connection = mlx_init();
    if (!fractal->mlx_connection)
    {
        mem_err();
    }
    fractal->mlx_window = mlx_new_window(fractal->mlx_connection,
                                         WIDTH,
                                         HEIGHT,
                                         fractal->name);
    if (!fractal->mlx_window)
    {
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        mem_err();
    }
    fractal->img.img_ptr = mlx_new_image(fractal->mlx_connection, WIDTH, HEIGHT);
    if (!fractal->img.img_ptr)
    {
        mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
        mlx_destroy_display(fractal->mlx_connection);
        free(fractal->mlx_connection);
        mem_err();
    }
    fractal->img.img_pixel_ptr = mlx_get_data_addr(fractal->img.img_ptr, &fractal->img.bits_per_pixel, &fractal->img.line_length, &fractal->img.endian);
    data_init(fractal);
    events_init(fractal);
}