NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_hexaconvert.c \
	  ft_printaddress.c \
	  ft_printf.c \
	  ft_putchar.c \
	  ft_putnbr.c \
	  ft_putstr.c \
	  ft_strlen.c \
	  ft_tolower.c \
	  ft_unputnbr.c \
	  ft_strlen.c \
	  ft_count.c

OBJ = $(SRC:%.c=%.o)

all : $(NAME)

$(NAME) :
	cc $(FLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJ)

clean:
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all clean fclean re