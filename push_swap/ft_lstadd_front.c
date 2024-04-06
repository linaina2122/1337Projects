/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:31:54 by hcharef           #+#    #+#             */
/*   Updated: 2022/05/17 11:31:59 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"push_swap.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	new->next = *lst;
	*lst = new;
}
	
// int	main()
// {
// 	t_list *list;
// 	t_list *new;
// 	char *str = "hello";
// 	char *str2 = "test";
// 	list = ft_lstnew(str);
// 	new = ft_lstnew(str2);
// 	ft_lstadd_front(&list, new);
// 	printf("%s", list->content);
// 	printf("%s", list->next->content);
// }