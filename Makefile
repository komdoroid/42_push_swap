# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkomurat <kkomurat@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 21:08:55 by kkomurat          #+#    #+#              #
#    Updated: 2026/05/25 22:48:55 by kkomurat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

SRCS =  chunk_sort.c \
		command_output.c \
		command_push.c \
		command_reverse_rotate.c \
		command_rotate.c \
		command_swap.c \
		disorder.c \
		flags.c \
		list.c \
		list_index.c \
		main.c \
		ps_split.c \
		radix_sort.c \
		simple.c \
		parse.c \
		bench_output.c \
		ps_utility.c
       
OBJS = $(SRCS:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
