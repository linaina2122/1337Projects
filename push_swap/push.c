/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 16:57:57 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 00:54:53 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_to_b(t_list **s1, t_list **s2)
{
	t_list	*tmp;

	if (ft_lstsize(*s1) == 0)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
	write(1, "pb\n", 3);
}

void	push_to_a(t_list **s2, t_list **s1)
{
	t_list	*tmp;

	if (ft_lstsize(*s2) == 0)
		return ;
	tmp = *s2;
	*s2 = (*s2)->next;
	tmp->next = *s1;
	*s1 = tmp;
	write(1, "pa\n", 3);
}
