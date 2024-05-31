#include "push_swap.h"


int	is_number(char *str)
{
	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);		
		++str;
	}
	return (1);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

// make this into parse_str_arr instead of argv specific
bool	parse_argv_for_valid_input(int argc, char **argv)
{
	char	*arg;
	//long	arg_to_long;
	int	arg_idx;
	int	cmp_idx;
	
	arg_idx = 1;
	while (arg_idx < argc)
	{
		arg = argv[arg_idx];
		if (!is_number(arg))
			return (false);
		//arg_to_long = atol(arg);
		//if (arg_to_long < INT_MIN || arg_to_long > INT_MAX)
			//return (-1);
		cmp_idx = 1;
		while (arg_idx + cmp_idx < argc)
		{
			if (ft_strcmp(arg, argv[arg_idx + cmp_idx]) == 0)
				return (false);
			++cmp_idx;
		}
		++arg_idx;
	}
	return (true);
}

// make this into parse_str_arr instead of argv specific
t_stack	*push_argv_onto_stack(t_stack *stack, int argc, char **argv)
{
	t_node	*new_node;
	//t_node	*duplicate_lst;
	char		*arg;
	long		arg_to_long;

	while(argc > 1)
	{
		arg = argv[argc - 1];
		arg_to_long = atoi(arg);
		new_node = create_node((int)arg_to_long);
		if (!new_node)
			return (NULL);
		push(stack, new_node);
		--argc;
	}
	return (stack);
}

int	print_error()
{
	return (write(2, "Error", 5));
}

int	opsomming(int n)
{
	if (n == 0)
		return 1;
	else
	{
		printf("%i ", n);
		//printf("%i ", 300 + n);
		return n + opsomming(n - 1);
	}
}

int main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	t_queue	a_operations;
	t_queue	b_operations;
	size_t	height;

	if (parse_argv_for_valid_input(argc, argv) == false)
		return (print_error());
	height = argc - 1;
	if (height <= 1)
		return (0);
	a.name = 'a';
	b.name = 'b';
	a.queue = &a_operations;
	b.queue = &b_operations;
	a.top = a.bottom = a.queue->top = a.queue->bottom = NULL;
	b.top = b.bottom = b.queue->top = b.queue->bottom = NULL;	
	if (push_argv_onto_stack(&a, argc, argv) == NULL)
		return (print_error);
	if (lst_map_values_to_indexes(a.top) == NULL)
		return (print_error);
	if (ordered_ascending (&a, 1) != height)
		sort_stack(&a, &b, height);
	print_sorting_operations(a.queue, b.queue);
	lst_clear(&a.top);
}




