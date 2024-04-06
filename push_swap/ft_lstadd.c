/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hcharef <hcharef@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 11:31:24 by hcharef           #+#    #+#             */
/*   Updated: 2022/05/23 18:06:23 by hcharef          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include       "push_swap.h"

void    ft_lastadd_back(t_list **lst, t_list *new)
{
    t_list *node;
    node = *lst;
    while(node->next  != NULL)
    {
        node  = node->next;
    }
    node->next = new;
    //new->next = NULL;
}

// int main()
// {
//     t_list *new;
//     t_list *tmp;
//     char *str = "hello";
//     char *str1 = "hi";
//     char  *str2 = "nop";
//     new = ft_lstnew(str);
//     ft_lastadd_back(&new, ft_lstnew(str1));
//     ft_lastadd_back(&new, ft_lstnew(str2));
//     tmp = new;
//     while(tmp != NULL)
//     {
//         printf("%s\n", tmp->content);
//         tmp = tmp->next;
//     }
// }