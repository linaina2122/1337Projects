# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/12 15:51:30 by waboutzo          #+#    #+#              #
#    Updated: 2022/11/21 22:37:21 by hcharef          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= minishell
RM		= rm -rf
CC		= cc
CFLAGS	= -Wall -Wextra -Werror -I /Users/${USER}/.brew/opt/readline/include
OBJ		= $(SRCS:.c=.o)

BUILT_INS	=	env echo pwd unset unset_x exit exit_x check_buils print_errors export export_x cd 

TOOLS		=	advanced_split double_pointer_lib free_node print_function tools\
				path_split

ECECUTION	=	exit_code  print utils pipes one execution

LEXER		=	get_tokens lexer lexer2 token

LIBFT		=	ft_atoi ft_isalpha ft_lstadd_back ft_lstdelone ft_lstsize ft_strcat ft_strdup \
				ft_isdigit ft_lstadd_front ft_lstlast ft_strchr ft_strjoin ft_strncmp \
				ft_calloc ft_itoa ft_lstclear ft_lstnew ft_split ft_strcmp ft_strlen ft_substr \
				ft_putstr_fd

PARSING		=	dollar_parsing quotes_parsing redirection_file  parsing_ii \
		   		get_important_data parsing_i parsing_iv parsing_v parsing_iii\

SRCS =  $(addsuffix .c, $(addprefix src/libft/, $(LIBFT))) \
		$(addsuffix .c, $(addprefix src/execution/, $(ECECUTION))) \
		$(addsuffix .c, $(addprefix src/parsing/, $(PARSING))) \
		$(addsuffix .c, $(addprefix src/lexer_tokens/, $(LEXER))) \
		$(addsuffix .c, $(addprefix src/built_ins/, $(BUILT_INS))) \
		$(addsuffix .c, $(addprefix src/tools/, $(TOOLS)))
%.o	: %.c
	@$(CC)  $(CFLAGS) -c $< -o $@

all : $(NAME)

$(NAME): main.c $(OBJ)
	@$(CC)  $(CFLAGS) $(OBJ) main.c -lreadline  -L /Users/${USER}/.brew/opt/readline/lib  -o $(NAME)
	@stty -echoctl

clean :
	@$(RM) $(OBJ)

fclean : clean
	@$(RM) $(NAME)

re : fclean all

.PHONY:			all clean fclean re bonus