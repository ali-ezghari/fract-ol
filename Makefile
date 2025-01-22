CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = utils.c events.c frac_render.c frac_init.c math_funcs.c fractol.c libft/ft_strncmp.c libft/ft_putstr_fd.c libft/ft_putchar_fd.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
