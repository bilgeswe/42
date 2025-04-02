NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
SRC = ft_printf.c \
	ft_putstr.c \
	ft_putadress.c \
	ft_putchar.c \
	ft_puthexadecimal_lowercase.c \
	ft_puthexadecimal_uppercase.c \
	ft_putnbr.c \
	ft_putunbr.c \
	ft_putptr.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
