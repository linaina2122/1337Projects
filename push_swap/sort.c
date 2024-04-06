/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 03:20:52 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 07:46:13 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

void	sort(t_list **s1, t_list **s2, int *arr, t_norm *n)
{
	n->argc -= 1;
	if (n->argc == 1 || n->argc == 2)
		first_sort(*s1);
	else if (n->argc == 3)
		three_sort(s1);
	else if (n->argc > 3 && n->argc <= 10)
		fifth_sort(s1, s2);
	else if (n->argc > 10 && n->argc < 150)
	{
		find_and_push(s1, s2, arr, n->argc);
		again_to_a(s1, s2, arr, n);
	}
	else
	{
		find_and_push2(s1, s2, arr, n->argc);
		again_to_a(s1, s2, arr, n);
	}
}
