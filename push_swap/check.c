/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 10:06:17 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/19 10:54:06 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static void	hundler_helper(t_list **s1, t_list **s2, char *op)
{
	if (ft_strcmp(op, "sa\n") == 0)
		swap_a2(*s1);
	else if (ft_strcmp(op, "sb\n") == 0)
		swap_b2(*s2);
	else if (ft_strcmp(op, "ss\n") == 0)
		swap_s2(*s1, *s2);
	else if (ft_strcmp(op, "pa\n") == 0)
		push_to_a2(s2, s1);
	else if (ft_strcmp(op, "pb\n") == 0)
		push_to_b2(s1, s2);
	else if (ft_strcmp(op, "ra\n") == 0)
		rotate_a2(s1);
	else if (ft_strcmp(op, "rb\n") == 0)
		rotate_b2(s2);
	else if (ft_strcmp(op, "rr\n") == 0)
		rotate2(s1, s2);
	else if (ft_strcmp(op, "rra\n") == 0)
		reverse_rotate_a2(s1);
	else if (ft_strcmp(op, "rrb\n") == 0)
		reverse_rotate_b2(s2);
	else if (ft_strcmp(op, "rrr\n") == 0)
		reverse_rotate2(s1, s2);
	else
		ft_error();
}

void	hundler(t_list **s1, t_list **s2)
{
	char	*op;

	op = get_next_line(0);
	while (op)
	{
		hundler_helper(s1, s2, op);
		op = get_next_line(0);
	}
}
