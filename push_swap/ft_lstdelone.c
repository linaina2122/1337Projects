#include    "push_swap.h"

void    ft_lstdelone(t_list *lst, void (*del)(void *))

{
    t_list *tmp;
    while(lst != NULL)
    {
        tmp = lst->content;
        lst = lst->next;
        del(tmp);
        free(tmp);
    }
}