NAME = so_long
CC = gcc
CFLAGS  = -Wall -Werror -Wextra -Iincludes -g
LDFLAGS = -Llibft -lft -Lmlx -lmlx_Linux -L/usr/lib -lXext -lX11 -lm -lbsd -lz
SRC = src/main.c \
	  src/parser.c \
	  src/error_table.c \
	  src/error.c \
	  src/utils.c \
	  src/graphics.c \
	  src/callbacks.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = libft

# COLOR

BLUE    := \033[38;5;75m
GREEN   := \033[38;5;82m
MAGENTA := \033[38;5;200m
RED		:= \033[38;5;196m
RESET	:= \033[0m

all: $(NAME)

%.o: %.c
	@echo "$(MAGENTA)[$(GREEN)+$(MAGENTA)] $(GREEN) $< -> $(MAGENTA)$@ $(RESET)"
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	make -C libft all
	make -C mlx all
	$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)
	@echo "$(MAGENTA)[$(GREEN)+$(MAGENTA)] $(GREEN) Created succesfully $(MAGENTA)$@ $(RESET)"

clean:
	@rm -rf $(OBJ)
	make -C libft clean
	make -C mlx clean

fclean: clean
	@rm -rf $(NAME)
	make -C libft fclean

re: fclean $(LIBX_NAME) $(NAME)

.PHONY:	all clean fclean re