/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:19:46 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 15:19:46 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "ft_printf.h"

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

// do something to handle malloc failures
void	enqueue(t_queue *queue, t_node *new)
{
	if (!new)
		return ;
	if (queue->head == NULL)
	{
		queue->head = new;
		queue->tail = queue->head;
		return ;
	}
	queue->tail->next = new;
	queue->tail = new;
}

t_node	*dequeue(t_queue *queue)
{
	t_node	*popped_node;

	if (queue->head == queue->tail)
		queue->tail = NULL;
	popped_node = queue->head;
	queue->head = queue->head->next;
	popped_node->next = NULL;
	return (popped_node);
}

void	flush_queue(t_queue *queue)
{
	const char	*operation[11] = {\
		"sa", "ra", "rra", "pb", \
		"sb", "rb", "rrb", "pa", \
		"ss", "rr", "rrr" };

	while (queue->head != NULL)
	{
		ft_printf("%s\n", operation[queue->head->value]);
		free(dequeue(queue));
	}
}
