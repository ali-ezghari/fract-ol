#include "fractol.h"

static void pixel_put(t_fractal *fractal, int x, int y, int color)
{
    int offset;

    offset = (fractal->img.line_length * y) + (x * (fractal->img.bits_per_pixel / 8));
    *((unsigned int *)(offset + fractal->img.img_pixel_ptr)) = color; // color the pixel
}

void handle_coordinates(int x, int y, t_fractal *fractal, int max_iter)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    z.x = 0.0;
    z.y = 0.0;
    i = 0;
    c.x = map(x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    c.y = map(y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y; // Change the Map window coordinates (0, WIDTH or HEIGHT) to plane coordinates (-2, 2)
    while (i < max_iter)
    {
        z = calc_mandel(z, c);
        if ((z.x * z.x + z.y * z.y) > ESCAPE_VALUE)
        {
            color = map(i, max_iter, BLACK, WHITE); // The color changes based on the number of iterations before escaping (darker near the Mandelbrot set)
            pixel_put(fractal, x, y, color);        // Render this pixel if it escapes before completing all iterations
            return;
        }
        i++;
    }
    pixel_put(fractal, x, y, BLACK); // render this pixel as black if it remains bounded for the entire iteration process
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