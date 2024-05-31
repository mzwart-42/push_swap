#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int exec_cost = 0;

void	swap(t_stack *stack)
{
	t_node	*top_node;
	t_node	*after_top_node;
	t_node	*operation;

	if (stack->top->next == NULL)
		return ;
	top_node = pop(stack);
	after_top_node = pop(stack);
	push(stack, top_node);
	push(stack, after_top_node);
	operation = create_node(swap_stack);
	enqueue(stack->queue, operation);
	exec_cost++;
	write(1, "s", 1);
	printf("%c\n", stack->name);
}

void	rotate(t_stack *stack)
{
	t_node	*top_node;
	t_node	*operation;

	if (stack->top->next == NULL)
		return ;
	top_node = pop(stack);
	stack->bottom->next = top_node;
	stack->bottom = top_node;
	operation = create_node(rotate_stack);
	enqueue(stack->queue, operation);
	exec_cost++;
	write(1, "r", 1);
	printf("%c\n", stack->name);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*node_before_bottom;
	t_node	*traversal_node;
	t_node	*operation;

	push(stack, stack->bottom);
	traversal_node = stack->top;
	while (traversal_node->next != stack->bottom)
		traversal_node = traversal_node->next;
	node_before_bottom = traversal_node;
	node_before_bottom->next = NULL;
	stack->bottom = node_before_bottom;
	operation = create_node(reverse_rotate_stack);
	enqueue(stack->queue, operation);
	exec_cost++;
	write(1, "rr", 2);
	printf("%c\n", stack->name);
}

void	pop_and_push(t_stack *src_stack, t_stack *dest_stack)
{
	t_node	*popped_node;	
	t_node	*operation;

	if (src_stack->top == NULL)
		return ;
	popped_node = pop(src_stack);
	push(dest_stack, popped_node);
	operation = create_node(pop_and_push_stack);
	enqueue(src_stack->queue, operation);
	exec_cost++;
	write(1, "p", 1);
	printf("%c\n", src_stack->name);
}
