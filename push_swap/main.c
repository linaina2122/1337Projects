
#include "push_swap.h"
int main(int argc, char **argv)
{
  int  *arr;
    t_list *stack;
      t_list *stackk;

      stackk = NULL;
    if (argc < 2)
    {
        write(1, "\n", 1);
        exit(1);
    }
    check_int(argv);
    check_dup(argc, argv);
    arr = sort_ref(argc, argv);
     check_sort(argc, argv);
    stack = stack_a(argc, argv);
    //  ft_first_sort(arr, stack, stackk);
    ft_first_sort(&stack, &stackk, argc, arr);
    // ft_first_sort(arr, stack, stackk);
    //    first_sort(stack);
    //  three_sort(&stack);
    //   fifth_sort(&stack, &stackk);





















  
    printf("---------------- stack a ----------------\n");
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}

    printf("---------------- stack b ----------------\n");
	while (stackk)
	{
		printf("%d\n", stackk->content);
		stackk = stackk->next;
	}
  }