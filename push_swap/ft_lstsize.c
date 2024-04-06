#include	"push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int count;
	count = 0;
	t_list *list;
	list = lst;
	while(list != NULL)
	{
		list = list->next;
		count++;
	}
	return(count);
}
// int	main()
// {
// 	t_list a, b, c, d;

// 	 a.content = 1;
// 	 b.content = 2;
// 	 c.content = 3;
// 	 d.content = 4;

// 	a.next = &b;
// 	b.next = &c;
// 	c.next = &d;
// 	d.next = NULL;
// 	printf("%d\n", ft_lstsize(&a));
// }


