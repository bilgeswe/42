CC = cc
CFLAGS = -Wall -Wextra -Werror -I$(LIBFT_DIR)

RM = rm -f
RMDIR = rm -rf

NAME = push_swap
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

SRC = errors.c \
      init_stack.c \
      sort_three.c \
      sort_utils.c \
      sort_above_three.c \
      min_to_top.c \
      swap.c \
      rev_rotate.c \
      rotate.c \
      push.c \
      ab_push.c \
      ba_push.c \
      push_swap.c \
      push_utils.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) all

clean:
	$(RM) $(OBJ)
	$(RMDIR) obj/
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re
