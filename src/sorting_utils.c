/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:22:24 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 15:22:24 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	consecutive_nodes_in_range(t_stack *stack, int lower, int upper)
{
	t_node	*traverse;
	int		counter;

	counter = 0;
	traverse = stack->top;
	while (traverse && traverse->value >= lower && traverse->value <= upper)
	{
		traverse = traverse->next;
		++counter;
	}
	return (counter);
}

int	unrotate_nodes(t_stack *stack, int lower, int upper)
{
	const int	height = upper - lower + 1;
	int			counter;

	counter = 0;
	while (stack->bottom && stack->bottom->value >= lower \
		&& stack->bottom->value <= upper)
	{
		reverse_rotate(stack);
		counter++;
		if (counter >= height)
			break ;
	}
	return (counter);
}

//
// int	lst_sequantial_nodes(t_node *lst, int start, int end, int step_size)
// {
// 	int	sequantial_nodes;
//
// 	sequantial_nodes = 0;
// 	while(lst && lst->value == start)
// 	{
// 		if (start == end)
// 			return (sequantial_nodes);
// 		lst = lst->next;
// 		start += step_size;
// 		++sequantial_nodes;
// 	}
// 	return (0);
// }
//
int	ordered_ascending(t_node *lst, int start, int end)
{
	int	ordered_nodes;

	ordered_nodes = 0;
	while (lst && lst->value == start)
	{
		if (start == end)
			return (ordered_nodes);
		lst = lst->next;
		++ordered_nodes;
		++start;
	}
	return (0);
}

int	ordered_descending(t_node *lst, int start, int end)
{
	int	ordered_nodes;

	ordered_nodes = 0;
	while (lst && lst->value == start)
	{
		if (start == end)
			return (ordered_nodes);
		lst = lst->next;
		++ordered_nodes;
		start--;
	}
	return (0);
}
