/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_a.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 11:54:26 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 07:57:26 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	to_a(int *arr, t_list **s2, t_list **s1, t_norm *n)
{
	if ((*s2)->content == arr[n->count])
	{
		push_to_a(s2, s1);
		n->count--;
	}
	else if ((*s2)->content != arr[n->count])
	{
		if (n->index == 0 || (*s2)->content > (ft_lstlast(*s1))->content)
		{
			push_to_a(s2, s1);
			rotate_a(s1);
			n->index++;
		}
		else
		{
			if (check_max(arr[n->count], s2) < (ft_lstsize(*s2)) / 2)
				rotate_b(s2);
			else
				reverse_rotate_b(s2);
		}
	}
}

void	again_to_a(t_list **s1, t_list **s2, int *arr, t_norm *n)
{	
	n->index = 0;
	n->count = n->argc - 1;
	while (n->count >= 0)
	{
		if (check_max(arr[n->count], s2) == -1)
		{
			reverse_rotate_a(s1);
			n->index--;
			n->count--;
		}
		else
			to_a(arr, s2, s1, n);
	}
}
