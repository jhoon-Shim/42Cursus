# **************************************************************************** #
#                                   RUSH02                                     
# **************************************************************************** #

NAME	:= rush-02

CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror

INCDIR	:= includes
SRCDIR	:= srcs
OBJDIR	:= objs

SRCS	:= $(SRCDIR)/main.c \
		   $(SRCDIR)/dict.c \
		   $(SRCDIR)/dict_load.c \
		   $(SRCDIR)/num.c  \
		   $(SRCDIR)/print.c \
		   $(SRCDIR)/print_block.c \
		   $(SRCDIR)/print_group.c \
		   $(SRCDIR)/str.c \
		   $(SRCDIR)/str_more.c \
		   $(SRCDIR)/utils.c \
		   $(SRCDIR)/fileio.c \
		   $(SRCDIR)/dict_parse.c

OBJS	:= $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCDIR)/rush02.h
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -I$(INCDIR) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
