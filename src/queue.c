/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:26:27 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:26:27 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	print_queued_operations(t_queue *operations)
{
	lst_iter_and_optimize(operations, cancel_out_rotations);
	lst_iter_and_optimize(operations, cancel_out_next_rotations);
	lst_iter_and_optimize(operations, replace_top_with_double);
	lst_iter_and_optimize(operations, insert_double_op_ahead);
	flush_queue(operations);
}
