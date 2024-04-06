/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 04:42:41 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:17:06 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	min_find(t_list **s1)
{
	int		tmp;
	t_list	*temp;

	temp = *s1;
	tmp = temp->content;
	temp = temp->next;
	while (ft_lstsize(temp))
	{
		if (tmp > temp->content)
			tmp = temp->content;
		temp = temp->next;
	}
	return (tmp);
}

int	find_index(t_list **s1)
{
	t_list	*tmp;
	int		index;

	tmp = *s1;
	index = 1;
	while (ft_lstsize(*s1) >= index)
	{
		if ((tmp)->content == min_find(s1))
			return (index);
		index++;
		tmp = (tmp)->next;
	}
	return (0);
}

void	push(t_list **s1, t_list **s2)
{
	if (find_index(s1) == 1)
		push_to_b(s1, s2);
	else if (find_index(s1) == ft_lstsize(*s1))
	{
		reverse_rotate_a(s1);
		push_to_b(s1, s2);
	}
	else if (find_index(s1) != 1 && find_index(s1) != ft_lstsize(*s1))
	{
		while (find_index(s1) != 1)
			rotate_a(s1);
		push_to_b(s1, s2);
	}
}

int	check_max(int max, t_list **s2)
{
	t_list	*tmp;
	int		index;

	tmp = *s2;
	index = 0;
	while (tmp)
	{
		if (tmp->content == max)
			return (index);
		tmp = tmp->next;
		index++;
	}
	return (-1);
}

void	sort_b(t_list **stack, int *arr, int argc)
{
	t_list	*tmp;

	tmp = *stack;
	if (tmp && ft_lstsize(tmp) > 1)
	{
		if (tmp->content < arr[(argc - 1) / 2])
			rotate_b(stack);
	}
}
