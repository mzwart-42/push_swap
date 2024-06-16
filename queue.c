#include "push_swap.h"

int	opt = 0;

bool	matching_operations(t_node *op1, t_node *op2)
{	
	if (!op1 || !op2)
		return (false);
	if (op1->value > pa || op2->value > pa)
		return (false);
	if (op1->value - op2->value == 4 || op2->value - op1->value == 4)
		return (true);
	return (false);
}

bool	opposite_stack(t_node *op1, t_node *op2)
{
	if (!op1 || !op2)
		return (true);
	if (op1->value >= ss || op2->value >= ss)
		return (false);
	if (op1->value < sb && op2->value >= sb)
		return (true);
	else if (op2->value < sb && op1->value >= sb)
		return (true);
	return (false);
}

//
// bool	delete_double_rotations(t_queue *queue, t_node *next_push_op)
// {
// 	int	rotation;
// 	int	reverse_rotation;
// 	t_node	*traverse;
//
// 	assert(queue->top );
// 	traverse = queue->top;
// 	rotation = traverse->value;
// 	if (rotation == ra ||rotation == rb)
// 		reverse_rotation = rotation + 1;
// 	else if (rotation == rra || rotation == rrb)
// 		reverse_rotation = rotation - 1;
// 	else
// 		return (false);
// 	while (traverse != next_push_op && traverse->value == rotation)
// 		traverse = traverse->next;
// 	if (traverse != NULL && traverse->value == reverse_rotation)
// 	{
// 		opt+= 2;
// 		//printf("double rot %i %i", queue->top->value, traverse->value);
// 		//print_lst(queue->top);
// 		//ft_lstdel_one(, traverse);
// 		free(pop(queue));
// 		return (true);
// 	}
// 	return (false);
// }
//

static t_node	*cancel_out_rotations(t_queue *q, t_node *start, t_node *end)
{
	int	rotation;
	int	reverse_rotation;
	t_node	*traverse;
	t_node	*next_op;

	rotation = start->value;
	if (rotation == ra || rotation == rb)
		reverse_rotation = rotation + 1;
	if (rotation == rra || rotation == rrb)
		reverse_rotation = rotation - 1;
	else
		return (NULL);
	traverse = start;
	while (traverse != end && traverse->value == rotation)
		traverse = traverse->next;
	if (traverse != end && traverse->value == reverse_rotation)
	{
		opt += 2;
		next_op = start->next;
		if (traverse == next_op)
			next_op = start->next->next;
		ft_lstdel_one(&q->top, start);
		ft_lstdel_one(&q->top, traverse);
		return (next_op);
	}
	return (NULL);
}

static t_node	*replace_with_double_operation(t_queue *q, t_node *start, t_node *end)
{
	const int	double_operation[7] = {ss ,rr , rrr, -1 , ss, rr, rrr};
	t_node		*traverse;

	traverse = start;
	while (traverse != end && !opposite_stack(start, traverse))
		traverse = traverse->next;
	if (matching_operations(start, traverse))
	{
		opt++;
		//printf("fix double \n");
		start->value = double_operation[start->value];
		ft_lstdel_one(&q->top, traverse);
		return (start);
	}
	return (NULL);
}

static t_node	*insert_double_operation_ahead(t_queue *queue, t_node *start, t_node *end)
{
	const int	double_operation[7] = {ss ,rr , rrr, -1 , ss, rr, rrr};
	t_node		*traverse;
	t_node		*next_top;
	
	if (!opposite_stack(start, start->next))
		return (NULL);
	traverse = start->next;
	while (traverse != end && opposite_stack(start, traverse))
	{
		if (matching_operations(start, traverse))
		{
			opt++;
			//printf("fix double in advance\n");
			traverse->value = double_operation[traverse->value];
			next_top = start->next;
			ft_lstdel_one(&queue->top, start);
			return (next_top);
		}
		traverse = traverse->next;
	}
	return (NULL);
}

static void	lst_iter_and_optimize(t_queue *queue, t_node *(*optimize_fn)(t_queue *, t_node *, t_node *))
{	
	t_node		*push_op;
	t_node		*top_operation;
	t_node		*new_top;

	if (!queue)
		return ;
	top_operation = queue->top;
	while (top_operation)
	{
		if ((top_operation->value == pb || top_operation->value >= pa))//&& top_operation->next != NULL)
		{
			top_operation = top_operation->next;
			continue;
		}
		if (push_op != NULL)
		{
			push_op = top_operation;
			while (push_op && push_op->value != pb && push_op->value != pa)
				push_op = push_op->next;
		}
		new_top = optimize_fn(queue, top_operation, push_op);
		if (new_top)
			top_operation = new_top;
		else
			top_operation = top_operation->next;
	}
}

void	print_queued_operations(t_queue *queue)
{
	//lst_iter_and_optimize(queue, cancel_out_rotations);
	lst_iter_and_optimize(queue, cancel_out_rotations);
	lst_iter_and_optimize(queue, replace_with_double_operation);
	lst_iter_and_optimize(queue, insert_double_operation_ahead); // fix this
	flush_queue(queue);
	//printf("%i ", opt);
}
/* failing insert_double
82 68 32 80 47 20 16 43 18 74 67 99 15 10 79 95 6 54 25 42 59 72 46 58 55 51 28 83 44 84 81 100 77 48 61 76 40 26 78 56 53 93 39 60 8 14 49 75 29 98 69 35 38 96 17 19 30 7 94 52 1 65 27 62 2 63 89 12 31 45 73 3 64 71 91 41 34 22 70 4 97 50 13 5 11 57 24 33 88 23 85 21 86 92 90 9 36 87 37 66
*/
