#include "push_swap.h"
#include <stdio.h>

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}

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

void	lst_clear(t_node **lst)
{
	t_node	*current_node;
	t_node	*tmp_for_free;

	current_node = *lst;
	while (current_node != NULL)
	{
		tmp_for_free = current_node;
		current_node = (current_node)->next;
		free(tmp_for_free);
	}
	*lst = NULL;
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

int	lst_len(t_node *lst)
{
	int	height;
	t_node	*traverse;

	height = 0;
	traverse = lst;
	while (traverse)
	{
		traverse = traverse->next;
		height++;
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