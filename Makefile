# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: riwatana <riwatana@student.42.jp>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/25 21:08:55 by kkomurat          #+#    #+#              #
#    Updated: 2026/05/27 23:16:55 by riwatana         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BONUS = checker

CC = cc
AR = ar rcs
CFLAGS = -Wall -Wextra -Werror

COMMON = command_push.c \
		command_reverse_rotate.c \
		command_rotate.c \
		command_swap.c \
		command_output.c \
		list.c \
		list_index.c \
		ps_split.c \
		parse.c \
		ps_utility.c \
		flags.c \
		simple.c \
		chunk_sort.c \
		radix_sort.c \
		disorder.c \
		bench_output.c 


PS_SRC = main.c \
		
CK_SRC = get_next_line.c  \
		get_next_line_utils.c \
		checker_bonus.c\
		checker_command_bonus.c

		
COMMON_OBJS = $(COMMON:.c=.o)
PS_OBJS     = $(PS_SRC:.c=.o)
CK_OBJS     = $(CK_SRC:.c=.o)

RM = rm -f

all: $(NAME)

$(NAME): $(COMMON_OBJS) $(PS_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(PS_OBJS) -o $(NAME)

bonus: $(BONUS)

$(BONUS): $(COMMON_OBJS) $(CK_OBJS)
	$(CC) $(CFLAGS) $(COMMON_OBJS) $(CK_OBJS) -o $(BONUS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(COMMON_OBJS) $(PS_OBJS) $(CK_OBJS)

fclean: clean
	$(RM) $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
