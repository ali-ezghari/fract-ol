#include "fractol.h"

int handle_key(int keycode, t_fractal *fractal)
{
    if (keycode == ESC_KEY)
    {
        free_close(fractal);
    }
    else if (keycode == LEFT_ARROW)
    {
        fractal->shift_x -= 0.5;
    }
    else if (keycode == RIGHT_ARROW)
    {
        fractal->shift_x += 0.5;
    }
    else if (keycode == UP_ARROW)
    {
        fractal->shift_y += 0.5;
    }
    else if (keycode == DOWN_ARROW)
    {
        fractal->shift_y -= 0.5;
    }
    else if (keycode == UP_ARROW)
    {
        fractal->shift_y += 0.5;
    }
    else if (keycode == O_KEY)
    {
        fractal->scale *= 1.1;
    }
    else if (keycode == Z_KEY)
    {
        fractal->scale *= 0.9;
    }
    draw_fractal(fractal);
    return 0;
}
int mouse_hook(int button, int x, int y, t_fractal *fractal)
{
    if (button == 5)
    {
        fractal->scale *= 0.9;
    }
    else if (button == 4)
    {
        fractal->scale *= 1.1;
    }
    draw_fractal(fractal);
    x += 1; // to remove
    y += 1; // to remove
    return 0;
}