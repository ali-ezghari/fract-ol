

#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx_linux/mlx.h"
#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <X11/X.h>

#define WIDTH 800
#define HEIGHT 800
#define MAX_ITER 80
#define ESCAPE_VALUE 4
#define WHITE 0xFFFFFF
#define BLACK 0x000000

// arrows
#define ESC_KEY 65307
#define RIGHT_ARROW 65363
#define LEFT_ARROW 65361
#define UP_ARROW 65362
#define DOWN_ARROW 65364

// extra for zooming 
#define Z_KEY 122
#define A_KEY 97
#define S_KEY 115
#define W_KEY 119
#define D_KEY 100

typedef struct s_img
{
    void *img_ptr;
    char *img_pixel_ptr;
    int bits_per_pixel;
    int line_length;
    int endian;
} t_img;

typedef struct s_fractal
{
    char *name;
    void *mlx_connection;
    void *mlx_window;
    t_img img;
    double shift_x;
    double shift_y;
    double scale;

} t_fractal;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

// main functions
void fractal_init(t_fractal *fractal);
void draw_fractal(t_fractal *fractal);

// math functions
t_complex calc_mandel(t_complex z, t_complex c);
double map(double coord, double range, double min, double max);

// events
int handle_key(int keycode, t_fractal *fractal);

// utils functions
int free_close(t_fractal *fractal);
void usage();
void mem_err();

#endif