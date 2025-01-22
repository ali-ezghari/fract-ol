#include "fractol.h"

static void pixel_put(t_fractal *fractal, int x, int y, int color)
{
    int offset;

    offset = (fractal->img.line_length * y) + (x * (fractal->img.bits_per_pixel / 8));
    *((unsigned int *)(offset + fractal->img.img_pixel_ptr)) = color; // color the pixel
}

static void handle_coordinates(int x, int y, t_fractal *fractal, int max_iter)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0.0;
    z.y = 0.0;
    i = 0;
    c.x = map(x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    c.y = map(y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y;
    while (i < max_iter)
    {
        z = calc_mandel(z, c);
        if ((z.x * z.x + z.y * z.y) > ESCAPE_VALUE)
        {
            color = map(i, max_iter, BLACK, WHITE);
            pixel_put(fractal, x, y, color);
            return;
        }
        i++;
    }
    pixel_put(fractal, x, y, BLACK);
}

void draw_fractal(t_fractal *fractal)
{
    int x;
    int y;

    y = 0;
    while (y < HEIGHT)
    {
        x = 0;
        while (x < WIDTH)
        {
            handle_coordinates(x, y, fractal, MAX_ITER);
            x++;
        }
        y++;
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}