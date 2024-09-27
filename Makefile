CC = cc

CFLAGS = -Wall -Werror -Wextra -g3 #-fsanitize=address

MLX_FLAGS = -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz

LIBFT_DIR = lib/

SRC_GNL = get_next_line/get_next_line.c

SRC_MAIN = main/cub3d.c main/check_extension.c main/parse.c \
		   main/split.c main/parse_rgb.c

SRC = $(SRC_MAIN) $(SRC_GNL)

OBJ = $(SRC:.c=.o)

LIBFT = $(LIBFT_DIR)libft.a

NAME = cub3D

GREEN				=	\033[0;32m
RED					=	\033[0;31m
YELLOW 				=   \033[1;33m
BLUE   				=   \033[1;34m
RESET  				=   \033[0m

all : $(NAME)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -o $(NAME)
	@printf "$(GREEN)✓  $(NAME)\n$(RESET)"

$(LIBFT):
	@make -C $(LIBFT_DIR) bonus --silent

clean:
	@rm -rf $(OBJ)
	@make -C $(LIBFT_DIR) clean --silent
	@printf "$(RED)✗  $(NAME): object files removed\n$(RESET)"

fclean: clean
	@rm -rf $(NAME) $(LIBFT)
	@printf "$(RED)✗  $(NAME): executables removed\n$(RESET)"

re: fclean all

.SILENT: