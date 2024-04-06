/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 14:44:53 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 16:29:14 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_list	*stack_a(int argc, char **argv)
{
	t_list	*stack;
	int		count;

	stack = NULL;
	count = 1;
	stack = ft_lstnew(ft_atoi(argv[count]));
	count++;
	while (count < argc)
	{
		ft_lastadd_back(&stack, ft_lstnew(ft_atoi(argv[count])));
		count++;
	}
	return (stack);
}
