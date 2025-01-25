#ifndef FRACTOL_H
#define FRACTOL_H

#include "mlx_linux/mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#include <X11/X.h>

#define WIDTH 800
#define HEIGHT 800
#define ESCAPE_VALUE 4
#define WHITE 0xFFFFFF
#define BLACK 0x000000

// fractals ids
#define MANDEL 1
#define JULIA 2
#define SHIP 3

// esc & arrows keycode
#define ESC_KEY 65307
#define RIGHT_ARROW 65363
#define LEFT_ARROW 65361
#define UP_ARROW 65362
#define DOWN_ARROW 65364

#define Z_KEY 122 // zoom in
#define O_KEY 111 // zoom out
#define M_KEY 109 // increase iterations
#define P_KEY 112 // decrease iterations

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
    int id;
    void *mlx_connection;
    void *mlx_window;
    t_img img;
    double shift_x;
    double shift_y;
    double scale;
    int iterations;
    double julia_x;
    double julia_y;
} t_fractal;

typedef struct s_complex
{
    double x;
    double y;
} t_complex;

// libft funcs
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
size_t ft_strlen(const char *s);
int ft_strncmp(const char *s1, const char *s2, size_t n);

// main functions
void fractal_init(t_fractal *fractal);
void draw_fractal(t_fractal *fractal);
void mouse_zoom(t_fractal *fractal, int mouse_x, int mouse_y, double zoom_factor);

// math functions
double map(double coord, double range, double min, double max);
t_complex calc_mandel(t_complex z, t_complex c);
t_complex calc_julia(t_complex z, t_complex c);
t_complex calc_ship(t_complex z, t_complex c);

// events
int handle_key(int keycode, t_fractal *fractal);
int mouse_hook(int button, int x, int y, t_fractal *fractal);

// utils functions
double atodbl(char *str);
void put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
int free_close(t_fractal *fractal);
void usage();
void mem_err();

#endif