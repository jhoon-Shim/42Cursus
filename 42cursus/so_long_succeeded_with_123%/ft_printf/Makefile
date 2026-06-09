NAME = libftprintf.a
LIBFT = libft.a
LIBFT_DIR = ./libft

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c ft_printf_utils.c ft_printf_chars.c ft_printf_numbers.c ft_printf_hex.c
BONUS_SRCS = ft_printf_bonus.c ft_printf_utils_bonus.c ft_printf_chars_bonus.c ft_printf_numbers_bonus.c ft_printf_hex_bonus.c

OBJS = $(SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

bonus: $(BONUS_OBJS)
	$(MAKE) -C $(LIBFT_DIR)
	cp $(LIBFT_DIR)/$(LIBFT) $(NAME)
	$(AR) $(NAME) $(BONUS_OBJS)

.PHONY: all clean fclean re bonus