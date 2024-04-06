#include    "struct.h"

void    ft_lstclear(t_list **lst, void (*del(void *)))

{
 if(&lst)
    del(&lst);
    free(&lst);
}