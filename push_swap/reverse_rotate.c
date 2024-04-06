/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 00:45:19 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 16:34:18 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	reverse_rotate_a(t_list **stack)
{
	int		temp;
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *stack;
	tmp1 = *stack;
	if (ft_lstsize(*stack) < 2)
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	temp = tmp->content;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	free (tmp);
	tmp1->next = NULL;
	ft_lstadd_front(stack, ft_lstnew(temp));
	write (1, "rra\n", 4);
}

void	reverse_rotate_b(t_list **stack)
{
	int		temp;
	t_list	*tmp;
	t_list	*tmp1;

	tmp = *stack;
	tmp1 = *stack;
	if (ft_lstsize(*stack) < 2)
		return ;
	while (tmp->next != NULL)
		tmp = tmp->next;
	temp = tmp->content;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	free (tmp);
	tmp1->next = NULL;
	ft_lstadd_front(stack, ft_lstnew(temp));
	write (1, "rrb\n", 4);
}

void	reverse_rotate(t_list **s1, t_list **s2)
{
	reverse_rotate_a(s1);
	reverse_rotate_b(s2);
	write (1, "rrr\n", 4);
}
