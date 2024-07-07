/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_subset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:29:26 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:29:26 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_bottom_3_ascending(t_stack *stack)
{
	const int	first = stack->top->value;
	const int	second = stack->top->next->value;
	const int	third = stack->top->next->next->value;

	if (first > second && second > third)
	{
		rotate(stack);
		swap(stack);
	}
	else if (first > second && first > third)
		rotate(stack);
	else if (first > second && first < third)
		swap(stack);
	else if (first < second && first > third)
		reverse_rotate(stack);
	else if (first < second && second > third)
	{
		swap(stack);
		rotate(stack);
	}
}

void	sort_bottom_3_descending(t_stack *stack)
{
	const int	first = stack->top->value;
	const int	second = stack->top->next->value;
	const int	third = stack->top->next->next->value;

	if (first < second && first < third)
	{
		rotate(stack);
		if (second < third)
			swap(stack);
	}
	else if (first < second && second > third)
		swap(stack);
	else if (first > second && first < third)
		reverse_rotate(stack);
	else if (first > second && second < third)
	{
		swap(stack);
		rotate(stack);
	}
}

static void	rotate_swap_reverse_rotate(t_stack *stack)
{
	rotate(stack);
	swap(stack);
	reverse_rotate(stack);
}

void	sort_3_ascending(t_stack *stack)
{
	const int	first = stack->top->value;
	const int	second = stack->top->next->value;
	const int	third = stack->top->next->next->value;

	if (first > second && first > third)
	{
		swap(stack);
		rotate_swap_reverse_rotate(stack);
		if (second > third)
			swap(stack);
	}
	else if (first > second && first < third)
		swap(stack);
	else if (first < second && second > third)
	{
		rotate_swap_reverse_rotate(stack);
		if (first > third)
			swap(stack);
	}
}

void	sort_3_descending(t_stack *stack)
{
	const int	first = stack->top->value;
	const int	second = stack->top->next->value;
	const int	third = stack->top->next->next->value;

	if (first > second && second < third)
	{
		rotate_swap_reverse_rotate(stack);
		if (first < third)
			swap(stack);
	}
	else if (first < second && second > third)
	{
		swap(stack);
		if (first < third)
			rotate_swap_reverse_rotate(stack);
	}
	else if (first < second && second < third)
	{
		swap(stack);
		rotate_swap_reverse_rotate(stack);
		swap(stack);
	}
}
