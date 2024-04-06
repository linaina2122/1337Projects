/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:32:52 by hcharef           #+#    #+#             */
/*   Updated: 2022/05/19 19:27:46 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list *ft_lstnew(int content)
{
	t_list *new;

	new = malloc(sizeof(t_list));
	if(!new)
		return(NULL);
	new->content = content;
	new->next = NULL; 
	return(new);
}

// int main()
// {
// 	t_list *list;

// 	char *str = "hello";
// 	list = ft_lstnew(str);
// 	printf("%s", list->content);
// }