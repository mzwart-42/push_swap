#include "push_swap.h"

int	unrotate_nodes(t_stack *stack, int lower , int upper)
{
	int	bottom_val;
	int	counter;

	counter = 0;
	bottom_val = stack->bottom->value;
	while (stack->bottom && stack->bottom->value >= lower && stack->bottom->value <= upper)
	{
		reverse_rotate(stack);
		counter++;
	}
	return (counter);
}

int	ordered_ascending(t_stack *stack, int lower)
{
	t_node	*lst;
	int	ordered_nodes;

	if (stack->top == NULL)
		return (0);
	lst = stack->top;
	ordered_nodes = 0;
	while(lst && lst->value == lower)
	{
		lst = lst->next;
		ordered_nodes++;
		lower++;
	}
	return (ordered_nodes);
}

int	ordered_descending(t_stack *stack, int upper)
{
	t_node	*lst;
	int	ordered_nodes;

	if (stack->top == NULL)
		return (0);
	lst = stack->top;
	ordered_nodes = 0;
	while(lst && lst->value == upper)
	{
		lst = lst->next;
		ordered_nodes++;
		upper--;
	}
	return (ordered_nodes);
}

