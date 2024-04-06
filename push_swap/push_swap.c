/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 12:52:49 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/19 18:13:17 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	int		*arr;
	t_list	*stack;
	t_list	*stackk;
	t_norm	n;

	stackk = NULL;
	if (argc > 1)
	{
		check_int(argv);
		check_dup(argc, argv);
		test(argv);
		arr = sort_ref(argc, argv, &n);
		if (check_sort(argc, argv))
			return (0);
		stack = stack_a(argc, argv);
		n.argc = argc;
		sort(&stack, &stackk, arr, &n);
		ft_check(&stack, arr);
	}
	return (0);
}
