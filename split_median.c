#include "push_swap.h"

static bool	push_smaller_or_equal(t_stack *stack, int median)
{
	if (stack->top->value <= median)
		return (1);
	return (0);
}

static bool	push_greater(t_stack *stack, int median)
{
	if (stack->top->value > median)
		return (1);
	return (0);
}

int	split_at_median(t_stack *src, t_stack *dest, int lower, int upper)
{	
	const int	median = (upper + lower) / 2;
	const int	height = (upper - lower) + 1;
	const	int	total_push_ops = (height / 2) + ((height % 2) * (src->name == 'a'));
	bool		(*compare_median)(t_stack *, int);
	int		push_operations;

	if (height == 10000000)
	{
		pop_and_push(src, dest);
		return (1);
	}
	compare_median = push_smaller_or_equal;
	if (src->name == 'b')
		compare_median = push_greater;
	push_operations = 0;
	while (push_operations < total_push_ops)
	{
		if (compare_median(src, median))
		{
			pop_and_push(src, dest);
			++push_operations;
		}
		else
			rotate(src);
	}
	assert(push_operations != 0 && push_operations != 1);
	return (push_operations);
}
