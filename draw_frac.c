#include "fractol.h"

static void draw_mandel(int x, int y, t_fractal *fractal, int max_iter)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = -1;
    z.x = 0;
    z.y = 0;
    c.x = map(x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    c.y = map(y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y; // Change the Map window coordinates (0, WIDTH or HEIGHT) to plane coordinates (-2, 2)
    while (++i < max_iter)
    {
        z = calc_mandel(z, c);
        if ((z.x * z.x + z.y * z.y) > ESCAPE_VALUE)
        {
            color = map(i, max_iter, BLACK, WHITE);   // The color changes based on the number of iterations before escaping (darker near the Mandelbrot set)
            put_color_to_pixel(fractal, x, y, color); // Render this pixel if it escapes before completing all iterations
            return;
        }
    }
    put_color_to_pixel(fractal, x, y, BLACK); // render this pixel as black if it remains bounded for the entire iteration process
}
static void draw_julia(int x, int y, t_fractal *fractal, int max_iter)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = -1;
    c.x = fractal->julia_x;
    c.y = fractal->julia_y;
    z.x = map(x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    z.y = map(y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y;
    while (++i < max_iter)
    {
        z = calc_julia(z, c);
        if ((z.x * z.x + z.y * z.y) > ESCAPE_VALUE)
        {
            color = map(i, max_iter, BLACK, WHITE);
            put_color_to_pixel(fractal, x, y, color);
            return;
        }
    }
    put_color_to_pixel(fractal, x, y, BLACK);
}
static void draw_ship(int x, int y, t_fractal *fractal, int max_iter)
{
    t_complex z;
    t_complex c;
    int i;
    int color;

    i = -1;
    z.x = 0;
    z.y = 0;
    c.x = map(x, WIDTH, -fractal->scale, fractal->scale) + fractal->shift_x;
    c.y = map(y, HEIGHT, fractal->scale, -fractal->scale) + fractal->shift_y;
    while (++i < max_iter)
    {
        z = calc_ship(z, c);
        if ((z.x * z.x + z.y * z.y) > ESCAPE_VALUE)
        {
            color = map(i, max_iter, BLACK, WHITE);
            put_color_to_pixel(fractal, x, y, color);
            return;
        }
    }
    put_color_to_pixel(fractal, x, y, BLACK);
}
void draw_fractal(t_fractal *fractal)
{
    int x;
    int y;

    y = -1;
    while (++y < HEIGHT)
    {
        x = -1;
        while (++x < WIDTH)
        {
            if (fractal->id == MANDEL)
                draw_mandel(x, y, fractal, fractal->iterations);
            else if (fractal->id == JULIA)
                draw_julia(x, y, fractal, fractal->iterations);
            else if (fractal->id == SHIP)
                draw_ship(x, y, fractal, fractal->iterations);
        }
    }
    mlx_put_image_to_window(fractal->mlx_connection, fractal->mlx_window, fractal->img.img_ptr, 0, 0);
}