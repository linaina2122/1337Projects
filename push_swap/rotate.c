/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 16:11:57 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 16:33:53 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	rotate_a(t_list **stack)
{
	int		temp;
	t_list	**tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->content;
	tmp = stack;
	free (*tmp);
	*tmp = (*tmp)->next;
	ft_lastadd_back(tmp, ft_lstnew(temp));
	write (1, "ra\n", 3);
}

void	rotate_b(t_list **stack)
{
	int		temp;
	t_list	**tmp;

	if (ft_lstsize(*stack) < 2)
		return ;
	temp = (*stack)->content;
	tmp = stack;
	free (*tmp);
	*tmp = (*tmp)->next;
	ft_lastadd_back(tmp, ft_lstnew(temp));
	write (1, "rb\n", 3);
}

void	rotate(t_list **s1, t_list **s2)
{
	rotate_a(s1);
	rotate_b(s2);
	write (1, "rr\n", 3);
}
