#include "push_swap.h"
#include <unistd.h>
#include <stdio.h>

int exec_cost = 0;

static void	enqueue_or_nuke_everything(t_node *operation, t_stack *stack)
{
	if (operation)
	{
		enqueue(stack->queue, operation);
		return ;
	}
	flush_queue(stack->queue);
	lst_clear(&stack->top);	
	lst_clear(&stack->other_stack_to_free->top);
	error_exit();
}

void	swap(t_stack *stack)
{
	t_node	*top_node;
	t_node	*after_top_node;
	t_node	*operation;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	top_node = pop(stack);
	after_top_node = pop(stack);
	push(stack, top_node);
	push(stack, after_top_node);
	if (stack->name == 'a')
		operation = create_node(sa);
	else
		operation = create_node(sb);
	enqueue_or_nuke_everything(operation, stack);
}

void	rotate(t_stack *stack)
{
	t_node	*top_node;
	t_node	*operation;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	top_node = pop(stack);
	stack->bottom->next = top_node;
	stack->bottom = top_node;
	if (stack->name == 'a')
		operation = create_node(ra);
	else
		operation = create_node(rb);
	enqueue_or_nuke_everything(operation, stack);
}

void	reverse_rotate(t_stack *stack)
{
	t_node	*node_before_bottom;
	t_node	*traversal_node;
	t_node	*operation;

	if (stack->top == NULL || stack->top->next == NULL)
		return ;
	push(stack, stack->bottom);
	traversal_node = stack->top;
	while (traversal_node->next != stack->bottom)
		traversal_node = traversal_node->next;
	node_before_bottom = traversal_node;
	node_before_bottom->next = NULL;
	stack->bottom = node_before_bottom;

	if (stack->name == 'a')
		operation = create_node(rra);
	else
		operation = create_node(rrb);
	enqueue_or_nuke_everything(operation, stack);
}

void	pop_and_push(t_stack *src_stack, t_stack *dest_stack)
{
	t_node	*popped_node;	
	t_node	*operation;

	if (src_stack->top == NULL)
		return ;
	popped_node = pop(src_stack);
	push(dest_stack, popped_node);
	if (src_stack->name == 'a')
		operation = create_node(pa);
	else
		operation = create_node(pb);
	enqueue_or_nuke_everything(operation, src_stack);
}
