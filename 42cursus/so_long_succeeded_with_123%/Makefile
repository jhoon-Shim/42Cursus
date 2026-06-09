NAME        = so_long
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Directories
MLX_DIR     = ./minilibx-linux
LIBFT_DIR   = ./libft
PRINTF_DIR  = ./ft_printf

# Flags & Libraries
MLX_LNK     = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
LIBFT_LNK   = -L$(LIBFT_DIR) -lft
PRINTF_LNK  = -L$(PRINTF_DIR) -lftprintf
INC         = -I. -I$(MLX_DIR) -I$(LIBFT_DIR) -I$(PRINTF_DIR)

# Mandatory Sources
SRCS        = main.c map_parse.c map_check.c graphics.c engine.c map_check2.c
OBJS        = $(SRCS:.c=.o)

# Bonus Sources
SRCS_BN     = main_bonus.c map_parse_bonus.c map_check_bonus.c graphics_bonus.c engine_bonus.c map_check2_bonus.c
OBJS_BN     = $(SRCS_BN:.c=.o)

# Flag for bonus
BN_FLAG     = .bonus_flag

all: $(NAME)

$(NAME): $(OBJS)
	@rm -f $(BN_FLAG)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS) $(MLX_LNK) $(LIBFT_LNK) $(PRINTF_LNK) -o $(NAME)

# Bonus Rule
bonus: $(BN_FLAG)

$(BN_FLAG): $(OBJS_BN)
	@rm -f $(NAME)
	@make -C $(MLX_DIR)
	@make -C $(LIBFT_DIR)
	@make -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) $(OBJS_BN) $(MLX_LNK) $(LIBFT_LNK) $(PRINTF_LNK) -o $(NAME)
	@touch $(BN_FLAG)

%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
	@make clean -C $(MLX_DIR)
	@make clean -C $(LIBFT_DIR)
	@make clean -C $(PRINTF_DIR)
	rm -f $(OBJS) $(OBJS_BN) $(BN_FLAG)

fclean: clean
	@make fclean -C $(LIBFT_DIR)
	@make fclean -C $(PRINTF_DIR)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus