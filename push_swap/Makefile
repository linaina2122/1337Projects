NAME = 	push_swap

SRCS =	check_args.c \
		ft_atoi.c \
  		utils.c \
  		bigger_sort.c \
  		reverse_rotate.c \
  		sort.c \
  		small_sort.c \
  		rotate.c \
  		swap.c \
  		push.c \
  		stack.c \
		libft_fun.c \
  		push_swap.c \
  		big_sort.c \
		to_a.c \
		ft_utils.c \
		linked_list_fun.c

OBJS =	$(SRCS:.c=.o)

CNAME = checker

BONUS = check_args.c \
		stack.c \
		swap_operations.c \
		reverse_operations.c \
		rotate_operations.c \
		push_operations.c \
		check.c \
		checker.c \
		ft_atoi.c \
		linked_list_fun.c \
		libft_fun.c \
		get_next_line.c \
		ft_utils.c \

OBJS_BONUS = $(BONUS:.c=.o)

RM =	rm -rf

all:	$(NAME)

 CFLAGS = -Wall -Wextra -Werror

$(NAME):$(OBJS)
	$(CC) $(OBJS) $(CFLAGS) -o $(NAME)


clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean:	clean 
		$(RM) $(NAME) $(CNAME) 

re:		fclean all bonus
bonus : $(OBJS_BONUS) $(CNAME)

$(CNAME):
	$(CC) $(OBJS_BONUS) $(CFLAGS) -o $(CNAME)

.PHONY:	all clean fclean re bonus
