/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_optimizations.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 12:09:31 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 15:31:43 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*cancel_out_rotations(t_queue *queue, t_node *start, t_node *end)
{
	int		rotation;
	int		reverse_rotation;
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
		next_op = start->next;
		if (traverse == next_op)
			next_op = start->next->next;
		ft_lstdel_one(&queue->head, start);
		ft_lstdel_one(&queue->head, traverse);
		return (next_op);
	}
	return (NULL);
}

t_node	*cancel_out_next_rotations(t_queue *queue, t_node *start, t_node *end)
{
	const int	rotation = start->value;
	int			reverse_rotation;
	t_node		*traverse;
	t_node		*next_op;

	if (rotation == ra || rotation == rb)
		reverse_rotation = rotation + 1;
	if (rotation == rra || rotation == rrb)
		reverse_rotation = rotation - 1;
	else
		return (NULL);
	traverse = start;
	while (traverse != end && \
		(traverse->value == rotation || opposite_stack(start, traverse)))
		traverse = traverse->next;
	if (traverse != end && traverse->value == reverse_rotation)
	{
		next_op = start->next;
		if (traverse == next_op)
			next_op = start->next->next;
		ft_lstdel_one(&queue->head, start);
		ft_lstdel_one(&queue->head, traverse);
		return (next_op);
	}
	return (NULL);
}

t_node	*replace_top_with_double(t_queue *queue, t_node *start, t_node *end)
{
	const int	double_operation[7] = {ss, rr, rrr, -1, ss, rr, rrr};
	t_node		*traverse;

	traverse = start;
	while (traverse != end && !opposite_stack(start, traverse))
		traverse = traverse->next;
	if (matching_operations(start, traverse))
	{
		start->value = double_operation[start->value];
		ft_lstdel_one(&queue->head, traverse);
		return (start);
	}
	return (NULL);
}

t_node	*insert_double_op_ahead(t_queue *queue, t_node *start, t_node *end)
{
	const int	double_operation[7] = {ss, rr, rrr, -1, ss, rr, rrr};
	t_node		*traverse;
	t_node		*next_top;

	if (!opposite_stack(start, start->next))
		return (NULL);
	traverse = start->next;
	while (traverse != end && opposite_stack(start, traverse))
	{
		if (matching_operations(start, traverse))
		{
			traverse->value = double_operation[traverse->value];
			next_top = start->next;
			ft_lstdel_one(&queue->head, start);
			return (next_top);
		}
		traverse = traverse->next;
	}
	return (NULL);
}

void	lst_iter_and_optimize(t_queue *queue,
t_node	*(*optimize_fn)(t_queue *queue, t_node *top, t_node *end))
{
	t_node		*push_op;
	t_node		*top_operation;
	t_node		*new_top;

	top_operation = queue->head;
	push_op = (void *)1;
	while (top_operation)
	{
		if ((top_operation->value == pb || top_operation->value >= pa))
		{
			top_operation = top_operation->next;
			continue ;
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
