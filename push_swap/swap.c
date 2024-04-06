/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 03:33:18 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:28:01 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	swap_a(t_list *stack)
{
	int	new;

	if (ft_lstsize(stack) == 1 || ft_lstsize(stack) == 0)
		return ;
	new = stack->content;
	stack->content = stack->next->content;
	stack->next->content = new;
	write (1, "sa\n", 3);
}

void	swap_b(t_list *stack)
{
	int	new;

	if (ft_lstsize(stack) == 1 || ft_lstsize(stack) == 0)
		return ;
	new = stack->content;
	stack->content = stack->next->content;
	stack->next->content = new;
	write (1, "sb\n", 3);
}

void	swap_s(t_list *stack_a, t_list *stack_b)
{
	swap_a(stack_a);
	swap_b(stack_b);
	write (1, "ss\n", 3);
}
