#include "push_swap.h"

void	ft_lstdel_one(t_node **head, t_node *node_to_remove)
{
	t_node	*traverse;

	if (node_to_remove == *head)
	{
		*head = (*head)->next;
		free(node_to_remove);
		return ;
	}
	traverse = *head;
	while (traverse && traverse->next != node_to_remove)
		traverse = traverse->next;
	if (traverse->next == NULL)
		return ;
	traverse->next = node_to_remove->next;
	free(node_to_remove);
	node_to_remove = NULL;
}

void	enqueue(t_queue *queue, t_node *new)
{		
	if (!new)
		return ; // do something to handle malloc failures

	if (queue->top == NULL)
	{
		queue->top = new;
		queue->bottom = queue->top;
		return ;
	}
	queue->bottom->next = new;

	queue->bottom = new;
}

void	flush_queue(t_queue *queue)
{
	const char	*operation[11] = { \
		"sa", "ra", "rra", "pa", \
		"sb", "rb", "rrb", "pb", \
		"ss", "rr", "rrr"};

	while (queue->top != NULL)
	{
		printf("%s\n", operation[queue->top->value]);
		free(pop(queue));
	}
}
