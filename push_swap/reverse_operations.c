/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:50:07 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:27:26 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	reverse_rotate_a2(t_list **stack)
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
}

void	reverse_rotate_b2(t_list **stack)
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
}

void	reverse_rotate2(t_list **s1, t_list **s2)
{
	reverse_rotate_a2(s1);
	reverse_rotate_b2(s2);
}
