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
	bool		(*stack_compare)(t_stack *, int);
	int		push_operations;

	assert(height > 1);
	stack_compare = push_smaller_or_equal;
	if (src->name == 'b')
		stack_compare = push_greater;
	push_operations = 0;
	while (push_operations < total_push_ops)
	{
		if (stack_compare(src, median))
		{
			pop_and_push(src, dest);
			++push_operations;
		}
		else
			rotate(src);
	}
	return (push_operations);
}
