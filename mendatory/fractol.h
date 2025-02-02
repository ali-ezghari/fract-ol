#ifndef FRACTOL_H
# define FRACTOL_H

# include "../mlx_linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <math.h>
# include <X11/X.h>

# define WIDTH 800
# define HEIGHT 800
# define ESCAPE_VALUE 4
# define WHITE 0xFFFFFF
# define BLACK 0x000000

# define MANDEL 1
# define JULIA 2
# define SHIP 3

# define ESC_KEY 65307

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixel_ptr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}		t_img;

typedef struct s_fractal
{
	char	*name;
	int		id;
	void	*mlx_connection;
	void	*mlx_window;
	t_img	img;
	double	scale;
	int		iterations;
	double	julia_x;
	double	julia_y;
}			t_fractal;

typedef struct s_complex
{
	double	x;
	double	y;
}			t_complex;

// libft functions
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
size_t		ft_strlen(const char *s);
int			compare(const char *s1, const char *s2);

// main functions
void		fractal_init(t_fractal *fractal);
void		draw_fractal(t_fractal *fractal);
void		mouse_zoom(t_fractal *fractal, int mouse_x,
				int mouse_y, double zoom);

// events functions
int			handle_key(int keycode, t_fractal *fractal);
int			mouse_hook(int button, int x, int y, t_fractal *fractal);

// utils functions
double		atodbl(char *str);
void		f_format_err(void);
void		put_color_to_pixel(t_fractal *fractal, int x, int y, int color);
int			free_close(t_fractal *fractal);
void		usage(void);
void		mem_err(void);
int			coord_check(t_fractal *fractal);
// math functions
t_complex	calc_julia(t_complex z, t_complex c);
t_complex	calc_mandel(t_complex z, t_complex c);
double		map(double coord, double range, double min, double max);
#endif
