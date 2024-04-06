/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:46:54 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:27:36 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	rotate_a2(t_list **stack)
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
}

void	rotate_b2(t_list **stack)
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
}

void	rotate2(t_list **s1, t_list **s2)
{
	rotate_a2(s1);
	rotate_b2(s2);
}
