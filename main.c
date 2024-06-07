#include "push_swap.h"
#include <string.h>

// Pretty much all functions where something can malloc fail will use error_exit
void	error_exit()
{
	write(2, "Error\n", 6);
	exit(-1);
}

// if only you could have multiple assignment on one line
void	init_stacks(t_stack *a, t_stack *b, t_queue *ops)
{
	a->name = 'a';
	b->name = 'b';
	a->top = NULL;
	b->top = NULL;
	a->bottom = NULL;
	b->bottom = NULL;
	ops->top = NULL;
	ops->bottom = NULL;
	a->queue = ops;
	b->queue = ops;
	a->other_stack_to_free = b;
	b->other_stack_to_free = a;
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_queue 	ops;
	char		**new_argv;
	int		height;

	init_stacks(&a, &b, &ops);
	if (argc == 2 && strchr(argv[1], ' '))
		split_quoted_argv_and_parse(argv[1], &a);
	else
	{
		parse_cmd_args(argc - 1, argv + 1);
		push_cmd_args_on_stack(argc - 1, argv + 1, &a);
	}	
	lst_map_values_to_indexes(a.top);
	sort_stack(&a, &b);	
	print_queued_operations(&ops);
	//flush_queue(&ops);
	lst_clear(&a.top);
}

int	opsomming(int n)
{
	if (n == 0)
		return 1;
	else
	{
		printf("%i ", n);
		printf("%i ", 300 + n);
		return n + opsomming(n - 1);
	}
}
