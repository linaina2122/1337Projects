/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:44:12 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:28:18 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	swap_a2(t_list *stack)
{
	int	new;

	if (ft_lstsize(stack) == 1 || ft_lstsize(stack) == 0)
		return ;
	new = stack->content;
	stack->content = stack->next->content;
	stack->next->content = new;
}

void	swap_b2(t_list *stack)
{
	int	new;

	if (ft_lstsize(stack) == 1 || ft_lstsize(stack) == 0)
		return ;
	new = stack->content;
	stack->content = stack->next->content;
	stack->next->content = new;
}

void	swap_s2(t_list *stack_a, t_list *stack_b)
{
	swap_a2(stack_a);
	swap_b2(stack_b);
}
