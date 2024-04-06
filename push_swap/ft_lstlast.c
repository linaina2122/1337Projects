/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:32:23 by hcharef           #+#    #+#             */
/*   Updated: 2022/05/17 11:32:30 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include    "push_swap.h"

t_list *ft_lstlast(t_list *lst)
{
    while(lst->next != NULL)
    {
        lst = lst->next;
    }
    return(lst);
}

// int main()
// {
//     t_list *list;
//     t_list *new;

//     char *str = "hello";
//     char *str1 = "hi";
//     char *str2 = "nop";
//     list = ft_lstnew(str);
//     ft_lstadd_front(&list, ft_lstnew(str1));
//     ft_lstadd_front(&list, ft_lstnew(str2));
//     new = ft_lstlast(list);
//     printf("%s\n",new->content);
// } 