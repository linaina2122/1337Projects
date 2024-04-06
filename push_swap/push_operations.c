/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 16:48:32 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 00:06:56 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	push_to_b2(t_list **s1, t_list **s2)
{
	t_list	*tmp;

	if (ft_lstsize(*s1) == 0)
		return ;
	tmp = *s1;
	*s1 = (*s1)->next;
	tmp->next = *s2;
	*s2 = tmp;
}

void	push_to_a2(t_list **s2, t_list **s1)
{
	t_list	*tmp;

	if (ft_lstsize(*s2) == 0)
		return ;
	tmp = *s2;
	*s2 = (*s2)->next;
	tmp->next = *s1;
	*s1 = tmp;
}
