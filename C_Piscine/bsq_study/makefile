# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jshim <jshim@student.42gyeongsan.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/11/09 12:42:04 by jshim             #+#    #+#              #
#    Updated: 2025/11/09 14:53:57 by jshim            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Makefile

CC		= cc
CFLAGS	= -Wall -Wextra -Werror
NAME	= bsq

# 소스 파일
SRCS	= main.c \
		  utils.c \
		  reader.c \
		  solver.c \
		  printer.c

# 오브젝트 파일
OBJS	= $(SRCS:.c=.o)

# 헤더 파일
INCS	= bsq.h

# 기본 룰: $(NAME)을 빌드
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

# .c 파일을 .o 파일로 컴파일하는 룰
%.o: %.c $(INCS)
	$(CC) $(CFLAGS) -c $< -o $@

# 빌드된 파일 삭제
clean:
	rm -f $(OBJS)

# 빌드된 파일 및 실행 파일 모두 삭제
fclean: clean
	rm -f $(NAME)

# fclean 실행 후 all 실행
re: fclean all

.PHONY: all clean fclean re