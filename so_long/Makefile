NAME = 	so_long

SRCS =	ft_put_images.c map_checking.c main.c get_next_line.c moves.c ext_check.c check.c

OBJS =	$(SRCS:.c=.o)
RM =	rm -f

all:	$(NAME)

CFLAGS = -Wall -Wextra -Werror

$(NAME): $(OBJS)
		Make -C libft
		$(CC) $(OBJS) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit -o $(NAME) libft/libft.a 

clean:
		Make clean -C libft
		$(RM) $(OBJS)

fclean:	clean
		Make fclean -C libft
		$(RM) $(NAME) $(OBJS)

re:		fclean all

.PHONY:	all clean fclean re
