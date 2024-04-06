/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/29 05:36:27 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/17 08:10:45 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	var_init_second(t_var *var, int argc)
{
	var->i = 0;
	var->position = 1;
	var->medium = (argc - 1) / 2;
	var->range = (argc - 1) / 8;
	var->min = var->medium - var->range;
	var->max = var->medium + var->range;
	var->count = var->min;
}

static	void	for_norm(t_var *var, int argc)
{
	var->max = var->max + var->range;
	var->min = var->min - var->range;
	var->position = 1;
	if (var->max > argc - 1 || var->min < 0)
	{
		var->max = argc - 1;
		var->min = 0;
	}
}

static	int	check(int *arr, t_list *tmp, t_var *var)
{
	while (tmp)
	{
		var->count = var->min;
		while (var->count <= var->max)
		{
			if (arr[var->count++] == tmp->content)
			{
				var->nbr = tmp->content;
				return (1);
			}
		}
		var->position++;
		tmp = tmp->next;
	}
	return (0);
}

t_var	biger_sort(int *arr, t_list **stack, int argc)
{
	t_var	var;
	t_list	*tmp;

	tmp = *stack;
	var_init_second(&var, argc);
	while (var.i++ < 8)
	{
		if (check(arr, tmp, &var) == 1)
			return (var);
		for_norm (&var, argc);
		tmp = *stack;
	}
	var.position = 0;
	return (var);
}

void	find_and_push(t_list **s1, t_list **s2, int *arr, int argc)
{
	t_var	var;

	var = biger_sort(arr, s1, argc);
	while (var.position)
	{
		while ((*s1)->content != var.nbr)
		{
			if (var.position < (argc - 1) / 2)
				rotate_a(s1);
			else
				reverse_rotate_a(s1);
		}
		push_to_b(s1, s2);
		sort_b(s2, arr, argc);
		var = biger_sort(arr, s1, argc);
	}
}
