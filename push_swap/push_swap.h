/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 09:39:27 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/19 18:26:47 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef     PUSH_SWAP_H
# define    PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}t_list;

typedef struct s_var
{
	int	i;
	int	nbr;
	int	position;
	int	count;
	int	medium;
	int	range;
	int	min;
	int	max;
}t_var;

typedef struct s_norm
{
	int	count1;
	int	count2;
	int	count;
	int	argc;
	int	index;
	int	i;
	int	j;
}t_norm;

void	ft_lstadd_front(t_list **lst, t_list *new);
void	check_int(char **num);
void	check_dup(int argc, char **argv);
void	ft_lastadd_back(t_list **lst, t_list *new);
void	push_to_b(t_list **s1, t_list **s2);
void	push_to_a(t_list **s2, t_list **s1);
void	push_to_b2(t_list **s1, t_list **s2);
void	push_to_a2(t_list **s2, t_list **s1);
void	swap_s(t_list *stack_a, t_list *stack_b);
void	swap_a(t_list *stack);
void	swap_b(t_list *stack);
void	swap_s2(t_list *stack_a, t_list *stack_b);
void	swap_a2(t_list *stack);
void	swap_b2(t_list *stack);
void	rotate_a(t_list **stack);
void	rotate_b(t_list **stack);
void	rotate(t_list **s1, t_list **s2);
void	rotate_a2(t_list **stack);
void	rotate_b2(t_list **stack);
void	rotate2(t_list **s1, t_list **s2);
int		ft_strcmp(const char *s1, const char *s2);
void	reverse_rotate_a(t_list **stack);
void	reverse_rotate_b(t_list **stack);
void	reverse_rotate(t_list **s1, t_list **s2);
void	reverse_rotate_a2(t_list **stack);
void	reverse_rotate_b2(t_list **stack);
void	reverse_rotate2(t_list **s1, t_list **s2);
void	push(t_list **s1, t_list **s2);
void	three_sort(t_list **stack);
void	fifth_sort(t_list **s1, t_list **s2);
void	first_sort(t_list *stack);
int		check_sort(int argc, char **argv);
void	sort_b(t_list **stack, int *arr, int argc);
void	find_and_push(t_list **s1, t_list **s2, int *arr, int argc);
void	sort_b2(t_list **stack);
void	find_and_push2(t_list **s1, t_list **s2, int *arr, int argc);
void	again_to_a(t_list **s1, t_list **s2, int *arr, t_norm *n);
void	sort(t_list **s1, t_list **s2, int *arr, t_norm *n);
int		ft_check(t_list **stack, int *arr);
void	to_a(int *arr, t_list **s2, t_list **s1, t_norm *n);
void	ft_error(void);
void	*ft_memset(void *b, int c, size_t len);
void	hundler(t_list **s1, t_list **s2);
int		ft_atoi(const char *str);
int		ft_lstsize(t_list *lst);
int		min_find(t_list **s1);
int		find_index(t_list **s1);
int		*sort_ref(int argc, char **argv, t_norm *n);
int		check_max(int max, t_list **s2);
int		ft_strlen(const char *s);
char	*ft_strdup(const char *s1);
t_list	*ft_lstlast(t_list *lst);
t_list	*stack_a(int argc, char **argv);
t_list	*ft_lstnew(int content);
t_var	biger_sort(int *arr, t_list **stack, int argc);
t_var	bigest_sort(int *arr, t_list **stack, int argc);

void	test(char **argv);
#endif