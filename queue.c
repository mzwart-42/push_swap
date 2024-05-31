#include "push_swap.h"




void	print_sorting_operations(t_queue *a, t_queue *b)
{
	t_node	*traverse_a;	
	t_node	*traverse_b;	

	traverse_a = a->top;
	while (traverse_a != NULL)
	{
		traverse_a = traverse_a->next;	
	}


}

void	enqueue(t_queue *q, t_node *new)
{		
	if (!new)
		return ; // do something to handle malloc failures

	if (q->top == NULL)
	{
		q->top = new;
		q->bottom = q->top;
		return ;
	}
	q->bottom->next = new;
	q->bottom = new;
}
//
//int main()
//{
//	t_queue	operations;
//	t_stack	stack_a;
//	t_node	*op;
//
//	stack_a.queue = &operations;
//	stack_a.queue->top = stack_a.queue->bottom = NULL;
//	enqueue(stack_a.queue, create_node(swap_stack));
//	enqueue(stack_a.queue, create_node(pop_and_push_stack));
//
//	op = pop(stack_a.queue);
//	printf("%i\n", op->value);
//	free(op);
//	op = pop(stack_a.queue);
//	printf("%i\n", op->value);
//	free(op);
//}
