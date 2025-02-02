GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m
GREEN_CHECK = \033[32m✅\033[0m

CC = cc
FLAGS = -Wall -Wextra -Werror
SRCS = mendatory/utils.c mendatory/events.c mendatory/draw_frac.c mendatory/frac_init.c mendatory/calc_funcs.c mendatory/fractol.c mendatory/libft_funcs.c mendatory/atodbl.c
SRCSB = bonus/utils_bonus.c bonus/events_bonus.c bonus/draw_frac_bonus.c bonus/frac_init_bonus.c bonus/calc_funcs_bonus.c bonus/fractol_bonus.c bonus/libft_funcs_bonus.c bonus/atodbl_bonus.c
OBJS = $(SRCS:.c=.o)
OBJSB = $(SRCSB:.c=.o)
NAME = fractol

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -O3 -c $< -o $@
	@echo "$(GREEN)Compiled $< $(GREEN_CHECK)$(RESET)"

$(NAME): $(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)Mandatory: $(NAME) was created $(GREEN_CHECK)$(RESET)"
	
bonus: $(OBJSB)
	@$(CC) $(FLAGS) $(OBJSB) -Lmlx_linux -lmlx_Linux -lXext -lX11 -lm -o $(NAME)
	@echo "$(GREEN)Bonus: $(NAME) was created $(GREEN_CHECK)$(RESET)"

clean:
	@rm -f $(OBJS) $(OBJSB)
	@echo "$(RED)Removing object files...$(RESET)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)Removing $(NAME)...$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus
