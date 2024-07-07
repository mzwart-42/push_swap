/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:23:47 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 15:29:15 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static bool	compare_top_with_pivot(t_stack *stack, int pivot)
{
	if (stack->name == 'a')
		return (stack->top->value <= pivot);
	else
		return (stack->top->value > pivot);
}

/* 
 * if stack is a all nodes lower than and equal to pivot are pushed on b
 * if stack is b all higher nodes bigger than the pivot are pushed on a
*/
int	split_at_median(t_stack *stack, int lower, int upper)
{
	const int	median = (upper + lower) / 2;
	const int	height = (upper - lower) + 1;
	int			total_push_ops;
	int			push_operations;

	total_push_ops = height / 2;
	if (stack->name == 'a')
		total_push_ops += height % 2;
	push_operations = 0;
	while (push_operations < total_push_ops)
	{
		if (compare_top_with_pivot(stack, median))
		{
			pop_and_push(stack, stack->other_stack);
			++push_operations;
		}
		else
			rotate(stack);
	}
	return (push_operations);
}

int	split_into_three_chunks(t_stack *a, t_stack *b, int height)
{
	const int	lower_chunk_limit = height / 3;
	const int	middle_chunk_limit = lower_chunk_limit * 2;
	int			push_operations;

	push_operations = 0;
	while (push_operations < middle_chunk_limit)
	{
		if (a->top->value <= lower_chunk_limit)
		{
			pop_and_push(a, b);
			rotate(b);
			push_operations++;
		}
		else if (a->top->value <= middle_chunk_limit)
		{
			pop_and_push(a, b);
			push_operations++;
		}
		else
			rotate(a);
	}
	return (push_operations);
}
