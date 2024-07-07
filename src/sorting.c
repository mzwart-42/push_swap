/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 15:20:05 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 15:20:05 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	split_or_sort_a(t_stack *a, t_stack *b, int lower, int upper);

static void	split_or_sort_b(t_stack *a, t_stack *b, int lower, int upper);

static void	split_or_sort_b(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = upper - lower + 1;
	const bool	height_is_even = !(height % 2);
	int			pushed;

	if (height <= 3 || ordered_descending(b->top, lower, upper))
	{
		if (height == 2 && b->top->value < b->top->next->value)
			swap(b);
		else if (lst_len(b->top) == 3)
			sort_bottom_3_descending(b);
		else if (height == 3)
			sort_3_descending(b);
		pushed = height;
		while (pushed--)
			pop_and_push(b, a);
		return ;
	}
	pushed = split_at_median(b, lower, upper);
	if (pushed == -1)
		return ;
	if (lower != 1)
		unrotate_nodes(b, lower, lower + pushed - height_is_even);
	split_or_sort_a(a, b, (upper - pushed) + 1, upper);
	split_or_sort_b(a, b, lower, lower + pushed - height_is_even);
}

static void	split_or_sort_a(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = upper - lower + 1;
	const bool	height_is_odd = height % 2;
	int			pushed;

	if (height <= 3 || ordered_ascending(a->top, lower, upper))
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else if (height == 3)
			sort_3_ascending(a);
		return ;
	}
	pushed = split_at_median(a, lower, upper);
	unrotate_nodes(a, upper - pushed + 1 + height_is_odd, upper);
	split_or_sort_a(a, b, lower + pushed, upper);
	split_or_sort_b(a, b, lower, lower + pushed - 1);
}

void	start_split_or_sort_a(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = upper - lower + 1;
	int			pushed;

	if (height <= 3 || ordered_ascending(a->top, lower, upper))
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else if (height == 3)
			sort_3_ascending(a);
		return ;
	}
	pushed = split_at_median(a, lower, upper);
	start_split_or_sort_a(a, b, lower + pushed, upper);
	split_or_sort_b(a, b, lower, lower + pushed - 1);
}

void	sort_stack(t_stack *a, t_stack *b, int height)
{
	const int	bottom_chunk = height / 3;
	const int	middle_chunk = (height / 3) * 2;

	if (height >= 30)
	{
		split_into_three_chunks(a, b, height);
		start_split_or_sort_a(a, b, middle_chunk + 1, height);
		split_or_sort_b(a, b, bottom_chunk + 1, middle_chunk);
		split_or_sort_b(a, b, 1, bottom_chunk);
	}
	else
		start_split_or_sort_a(a, b, 1, height);
}
