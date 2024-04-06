/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 17:17:38 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/19 11:59:16 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*stack;
	t_list	*stackk;
	int		*arr;
	t_norm	n;

	stackk = NULL;
	if (argc > 1)
	{
		check_int(argv);
		check_dup(argc, argv);
		test(argv);
		stack = stack_a(argc, argv);
		arr = sort_ref(argc, argv, &n);
		hundler(&stack, &stackk);
		if (ft_check(&stack, arr) && !ft_lstsize(stackk))
			write (1, "OK\n", 3);
		else
			write (1, "KO\n", 3);
	}
}
