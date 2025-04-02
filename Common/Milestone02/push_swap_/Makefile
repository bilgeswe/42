# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bakpulat <bakpulat@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/15 21:26:02 by bakpulat          #+#    #+#              #
#    Updated: 2025/03/20 15:03:47 by bakpulat         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
INCLUDE = push_swap.h Makefile

SRC = push_swap.c \
	  handle_errors.c \
	  stack_utils.c	\
	  fill_stack.c \
	  swap.c \
	  push.c \
	  reverse.c \
	  sort_utils.c \
	  movements.c \
	  sort.c \
	  rotate.c	

OBJ := $(SRC:.c=.o)

OBJ_BONUS := $(SRC_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<

bonus: $(OBJ_BONUS) $(INCLUDE)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJ_BONUS)

clean:
	$(RM) $(OBJ) $(OBJ_BONUS)

fclean: clean
	$(RM) $(NAME) $(NAME_BONUS)

re: fclean all

.PHONY: all clean fclean re bonus