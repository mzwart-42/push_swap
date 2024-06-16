#include "push_swap.h"
#include <stdio.h>

void	push(t_stack *stack, t_node *pushed_node)
{
	if (!stack->top)
		stack->bottom = pushed_node;
	pushed_node->next = stack->top;
	stack->top = pushed_node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*popped_node;

	if (stack->top == stack->bottom)
		stack->bottom = NULL;
	popped_node = stack->top;
	stack->top = stack->top->next;
	popped_node->next = NULL;
	return (popped_node);
}

int	stack_height(t_stack *stack)
{
	int		height;
	t_node	*traverse_stack;
	
	height = 0;
	traverse_stack = stack->top;
	while (traverse_stack)
	{
		traverse_stack = traverse_stack->next;
		height = 0;
	}
	return (height);
}

void	print_lst(t_node	*lst)
{
	while (lst != NULL)	
	{
		printf(" %i -", lst->value);
		lst = lst->next;
	}
	printf(">\n");
}


void	print_two_stacks(const t_stack *first_stack, const t_stack *second_stack)
{
	printf("\n============\n");
	printf(" stack A: \n");
	if (first_stack)
		print_lst(first_stack->top);
	printf(" stack B: \n");
	if (second_stack)
		print_lst(second_stack->top);
	printf("============\n");
}
