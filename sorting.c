#include "push_swap.h"

void	a_split(t_stack *a, t_stack *b, int lower, int upper);

//void	b_split(t_stack *a, t_stack *b, int lower, int upper);

int	b_optimizations(t_stack *a, t_stack *b, int lower, int upper)
{
	int	height;
	int	sorted;

	printf("tdaddsdd\n");
	height = (upper - lower) + 1;
	if (lower == 1 && ordered_ascending(b->top, lower, upper))
	{
		while (height--)
		{
			reverse_rotate(b);
			pop_and_push(b, a);
		}
	}
	else if (ordered_descending(b->top, upper, lower))
	{	
		printf("ordesdsdd");
		while(height--)
			pop_and_push(b, a);
	}
	else if (consecutive_nodes_in_range(b, lower, upper) == 3)
	{	
		printf("%i %i", lower, upper);
		print_lst(b->top);
		sort_3_descending(b);
		sorted = 3;
		while (sorted--)
			pop_and_push(b, a);
		error_exit(1);
		return (0);
	}
	else
		return (0);
	return (1);

}

// only subtract  1, for b_split upper limit, if height is even
void	b_split(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const bool	height_is_uneven = height % 2;
	int	pushed;

	pushed = consecutive_nodes_in_range(b, lower, upper);
	printf(" \n%i %i \n", pushed, height);
	printf("\n");
	if (consecutive_nodes_in_range(b, lower, upper) == 3 && height > 3)
	{	
		printf("%i %i", lower, upper);
		print_lst(b->top);
		sort_3_descending(b);
		pushed = 3;
		while (pushed--)
			pop_and_push(b, a);
		upper -= 3;
	}
	if (height <= 3)	
	{
		if (height == 2 && b->top->value < b->top->next->value)
			swap(b);
		else if (lst_len(b->top) == 3)
			sort_bottom_3_descending(b);
		else if (height == 3)
			sort_3_descending(b);
		while ((upper-- - lower) + 1 > 0)
			pop_and_push(b, a);
		return ;
	}

	pushed = split_at_median(b, a, lower, upper);
	if (lower != 1)
		unrotate_nodes(b, lower, lower + pushed - (!height_is_uneven));
	a_split(a, b, (upper - pushed) + 1, upper);
	b_split(a , b, lower, lower + pushed - (!height_is_uneven));
}

void	a_split(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	const bool	height_is_uneven = height % 2;
	int	pushed;

	if (ordered_ascending(a->top, lower, upper))
		return ;
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
		unrotate_nodes(a, upper - pushed + 1 + height_is_uneven, upper);
		lower += pushed;
		a_split(a, b, lower, upper);
		b_split(a, b, lower - pushed, lower - 1);
	}
}

void	intial_split_up_a(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	int	pushed;

	if (ordered_ascending(a->top, lower, upper))
		return ;
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
		lower += pushed;
		intial_split_up_a(a, b, lower, upper);
		b_split(a, b, lower - pushed, lower - 1);
	}
}

void	*sort_stack(t_stack *a, t_stack *b)
{
	const int	height = lst_len(a->top);
	int   ordered;

	if (height < 2)
		return (NULL);
	intial_split_up_a(a, b, 1, height);
	print_two_stacks(a, b);
	return (NULL);
}

