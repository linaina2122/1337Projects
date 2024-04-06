/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 10:40:20 by hcharef           #+#    #+#             */
/*   Updated: 2022/06/18 10:21:43 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

int	ft_check(t_list **stack, int *arr)
{
	t_list	*tmp;
	int		count;

	tmp = *stack;
	count = 0;
	while (tmp)
	{
		if (tmp->content == arr[count])
		{
			tmp = tmp->next;
			count++;
		}
		else if (tmp->content != arr[count])
			return (0);
	}
	return (1);
}

int	*sort_ref(int argc, char **argv, t_norm *n)
{
	int	tmp;
	int	*arr;

	arr = malloc(sizeof(int) * argc - 1);
	n->count1 = 1;
	n->count2 = 0;
	while (argc > n->count1)
	{
		arr[n->count2] = ft_atoi(argv[n->count1]);
		n->count2++;
		n->count1++;
	}
	n->count2 = 1;
	while (n->count2 < n->count1 - 1)
	{
		if (arr[n->count2] < arr[n->count2 - 1])
		{
			tmp = arr[n->count2 - 1];
			arr[n->count2 - 1] = arr[n->count2];
			arr[n->count2] = tmp;
			n->count2 = 0;
		}
		n->count2++;
	}
	return (arr);
}
