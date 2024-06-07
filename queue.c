#include "push_swap.h"

// doesn't work if the remove_node is the head
void	remove_node(t_node *head, t_node *remove_node)
{
	assert(head != remove_node);
	if (!head)
		return ;
	while (head && head->next != remove_node)
		head = head->next;
	if (head == NULL)
		return ;
}

void	print_and_dequeue(t_queue *q)
{
	const char	*op[11] = { \
		"sa", "ra", "rra", "pa", \
		"sb", "rb", "rrb", "pb", \
		"ss", "rr", "rrr"};

	assert(q->top);
	printf("%s\n", op[q->top->value]);
	free(pop(q));
}
bool	matching_operations(t_node *op1, t_node *op2)
{	
	if (!op1 || !op2)
		return (false);
	if (op1->value - op2->value == 4 || op2->value - op1->value == 4)
		return (true);
	return (false);
}

bool	opposite_stack(t_node *op1, t_node *op2)
{
	if (!op1 || !op2)
		return (true);
	if (op1->value < sb && op2->value >= sb)
		return (true);
	else if (op2->value < sb && op1->value >= sb)
		return (true);
	return (false);


}

bool	squish_double_rotations(t_queue *queue, t_node *next_push_op)
{
	int	rotation;
	int	reverse_rotation;
	t_node	*traverse;

	assert(queue->top );
	traverse = queue->top;
	rotation = traverse->value;
	if (rotation == ra ||rotation == rb)
		reverse_rotation = rotation + 1;
	else if (rotation == rra || rotation == rrb)
		reverse_rotation = rotation - 1;
	else
		return (false);
	if (rotation == ra)
	while (traverse != next_push_op && traverse->value == rotation)
		traverse = traverse->next;
	if (traverse != NULL && traverse->value == reverse_rotation)
	{
		print_lst(queue->top);
		remove_node(queue->top, traverse);
		free(pop(queue));
		return (true);
	}
	return (false);
}

// next_push_op node is node before the next push node
void	optimize_double_operation(t_queue *queue, t_node *next_push_op)
{
	const int	double_operations[7] = {ss ,rr , rrr, -1, ss, rr, rrr};
	t_node	*traverse;

	traverse = queue->top->next;
	if (opposite_stack(queue->top, queue->top->next))
	{
		while (traverse != next_push_op)
		{
			if (matching_operations(queue->top, traverse))
			{
				traverse->value = double_operations[traverse->value];
				free(pop(queue));
				return ;
			}
			traverse = traverse->next;
		}
	}
	while (traverse != next_push_op && !opposite_stack(queue->top, traverse))
		traverse = traverse->next;
	if (matching_operations(queue->top, traverse))
	{
		queue->top->value = double_operations[queue->top->value];
		remove_node(queue->top, traverse);
	}
}

void	print_queued_operations(t_queue *queue)
{
	t_node	*next_push_op;
	t_node	*head;
	bool		squished;

	while (queue->top != NULL)
	{
		if (queue->top->value == pa || queue->top->value >= pb)
		{
			print_and_dequeue(queue);
			continue;
		}
		next_push_op = queue->top->next;
		while (next_push_op != NULL)
		{
			if (next_push_op->value == pa || next_push_op->value == pb)
				break;	
			next_push_op = next_push_op->next;
		}
		squished = squish_double_rotations(queue, next_push_op);
		if (squished)
			continue;
		optimize_double_operation(queue, next_push_op);
		print_and_dequeue(queue);
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

void	flush_queue(t_queue *q)
{
	printf("flushing queue\n");
	while (q->top != NULL)
		print_and_dequeue(q);
}

//
//int main()
//{
//	t_queue	queue;
//	t_stack	stack_a;
//	t_node	*op;
//
//	stack_a.queue = &queue;
//	stack_a.queue->top = stack_a.queue->bottom = NULL;
//	enqueue(stack_a.queue, create_node(swap_stack));
//	enqueue(stack_a.queue, create_node(pop_and_push_stack));
//
//	op = pop(stack_a.queue);
//	printf("%i\n", op->top->value);
//	free(op);
//	op = pop(stack_a.queue);
//	printf("%i\n", op->top->value);
//	free(op);
//}
//
