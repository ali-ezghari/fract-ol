CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = utils.c events.c draw_frac.c frac_init.c calc_funcs.c fractol.c libft_funcs.c
OBJS = $(SRCS:.c=.o)
NAME = fractol

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -O3 -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME) 
	
clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
