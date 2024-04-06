/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 14:36:19 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 07:41:01 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_sort(t_list **stack)
{
	if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->next->content > (*stack)->content)
		swap_a(*stack);
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->next->content < (*stack)->content)
		reverse_rotate_a(stack);
	else if ((*stack)->content < (*stack)->next->content
		&& (*stack)->next->next->content < (*stack)->next->content)
	{
		reverse_rotate_a(stack);
		swap_a(*stack);
	}
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content < (*stack)->next->next->content)
		rotate_a(stack);
	else if ((*stack)->content > (*stack)->next->content
		&& (*stack)->next->content > (*stack)->next->next->content)
	{
		rotate_a(stack);
		swap_a(*stack);
	}
}

void	fifth_sort(t_list **s1, t_list **s2)
{
	int	count;

	count = ft_lstsize(*s1);
	while (count > 3)
	{
		push(s1, s2);
		count--;
	}
	three_sort(s1);
	while (ft_lstsize(*s2) > 0)
		push_to_a(s2, s1);
}

void	first_sort(t_list *stack)
{
	if (ft_lstsize(stack) == 1)
		exit (0);
	else if (ft_lstsize(stack) == 2)
	{
		if (stack->content > stack->next->content)
			swap_a(stack);
	}
}
