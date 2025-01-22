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
    else if (keycode == Z_KEY)
    {
        fractal->scale *= 0.9;
    }
    else if (keycode == A_KEY)
    {
        fractal->shift_x -= 0.005;
    }
    else if (keycode == D_KEY)
    {
        fractal->shift_x += 0.005;
    }
    else if (keycode == S_KEY)
    {
        fractal->shift_y -= 0.005;
    }
    else if (keycode == W_KEY)
    {
        fractal->shift_y += 0.005;
    }
    draw_fractal(fractal);
    return 0;
}