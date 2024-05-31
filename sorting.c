#include "push_swap.h"

bool	push_smaller_or_equal(t_stack *stack, int median)
{
	if (stack->top->value <= median)
		return (1);
	return (0);

}

bool	push_greater(t_stack *stack, int median)
{
	if (stack->top->value > median)
		return (1);
	return (0);
}

int	split_at_median(t_stack *src, t_stack *dest, int lower, int upper)
{	
	bool		(*cmp_median)(t_stack *, int);
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	int		operations;
	int		push_operations;
	int		temp;

	temp = (height / 2) + (height % 2);
	cmp_median = push_smaller_or_equal;
	if (src->name == 'b')
	{
		cmp_median = push_greater;
		temp -= (height % 2);
	}
	operations = 0;
	push_operations = 0;
	while (operations < height && push_operations < temp)
	{
		if (cmp_median(src, median))
		{
			pop_and_push(src, dest);
			++push_operations;
		}
		else
			rotate(src);
		++operations;
	}
	if (push_operations == 0 || push_operations == 1)
		exit(1);
	return (push_operations);
}

void	b_split(t_stack *a, t_stack *b, int lower, int upper);

void	a_split(t_stack *a, t_stack *b, int lower, int upper)
{
	int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	const bool	height_is_uneven = height % 2;
	int	pushed;
	int	temp;

	//printf("IN A SPLIT");
	//print_two_stacks(a, b);
	//printf("A split ::: %i %i %i:::\n", lower, upper, height);
	//printf("\n orderd nodes a %i > %i ----\n", lower + ordered_ascending(a, lower), upper);
	//printf("\n orderd desc a %i < %i ----\n", upper - ordered_descending(a, upper), lower);
	if (lower + ordered_ascending(a, lower) > upper)
		return ;
	pushed = 0;
	if (height <= 3)
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else if (height == 3)
			sort_3_ascending(a);
	}
	else
	{
		pushed = split_at_median(a, b, lower, upper);
		//print_two_stacks(a, b);
		unrotate_nodes(a, upper - pushed + 1 + height_is_uneven, upper);
		lower += pushed;
		//printf("::: %i %i ::: a split \n", lower, upper);
		a_split(a, b, lower, upper);
		//printf("::: %i %i ::: b split in a\n", lower - pushed, lower - 1);
		b_split(a, b, lower - pushed, lower - 1);
	}
}

// only subtract  1, for b_split upper limit, if height is even
void	b_split(t_stack *a, t_stack *b, int lower, int upper)
{
	int	height = (upper - lower) + 1;
	const bool	height_is_uneven = height % 2;
	int	pushed;

	//printf("IN B SPLIT");
	//printf("%i", height_is_uneven);
	//print_two_stacks(a, b);
	//printf("B split ::: %i %i %i:::\n", lower, upper, height);
	//printf("\n orderd nodes b %i < %i ----\n", upper - ordered_descending(b, upper), lower);
	//printf("\n orderd asc a %i > %i ----\n", lower + ordered_ascending(b, lower), upper);

	if (lower == 1 && lower + ordered_ascending(b , lower) > upper)
	{
		while (height--)
		{
			reverse_rotate(b);
			pop_and_push(b, a);
		}
		return ;
	}
	//printf("\n orderd nodes b %i < %i ----\n", upper - ordered_descending(b, upper), lower);
	if (upper - ordered_descending(b, upper) < lower)
	{	
		while(height--)
			pop_and_push(b, a);
		return ;
	}
	if (height <= 3)	
	{
		if (height == 2 && b->top->value < b->top->next->value)
			swap(b);
		else if (lst_len(b->top) == 3)
			sort_bottom_3_descending(b);
		else if (height == 3)
			sort_3_descending(b);
		while (height-- > 0)
			pop_and_push(b, a);
	}
	else
	{
		pushed = split_at_median(b, a, lower, upper);
		//print_two_stacks(a, b);
		if (lower > 1)
			unrotate_nodes(b, lower, lower + pushed - (!height_is_uneven));

		//while (lower != 1 && height-- - pushed > 0)
			//reverse_rotate(b);
		//////printf("::: %i %i ::: into a\n", upper - pushed + 1, upper);
		//////printf("::: %i %i %i::: b_split into a\n", upper - pushed, lower - 1, upper);
		////printf("::: %i %i ::: a split \n", lower + pushed, upper);
		////printf("::: %i %i %i ::: a split \n", (upper - pushed) + 1, upper, pushed);
		a_split(a, b, (upper - pushed) + 1, upper);
		//printf("::: %i %i ::: b split in b\n", lower, lower + pushed - (!height_is_uneven));
		//printf("::: %i %i ::: b split in b\n", lower, lower + pushed);
		b_split(a , b, lower, lower + pushed - (!height_is_uneven));
		//(a, b);
	}
}

int	intial_split_up_a(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	int	pushed;
	int	temp;

	pushed = 0;
	if (height <= 3)
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else 
			sort_3_ascending(a);
	}
	else
	{
		pushed = split_at_median(a, b, lower, upper);
		lower += pushed;
		//printf("MAIN split %i %i :::\n", lower, upper);
		////print_two_stacks(a, b);
		intial_split_up_a(a, b, lower, upper);
		//printf("MAIN RECUSRION into b %i %i :::\n", lower - pushed, lower - 1);
		////print_two_stacks(a, b);
		b_split(a, b, lower - pushed, lower - 1);
	}

}

void	*sort_stack(t_stack *a, t_stack *b, int height)
{
	int		pushed;
	int		ordered;

	pushed = 0;

	ordered = ordered_ascending(a, 1);

	intial_split_up_a(a, b, 1, height);
	//print_two_stacks(a, b);
	//printf("%i", exec_cost);
}
