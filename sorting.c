#include "push_swap.h"

void	a_split(t_stack *a, t_stack *b, int lower, int upper);

void	b_split(t_stack *a, t_stack *b, int lower, int upper);

int	order_for_height_4(t_stack *b, t_stack *a, int upper)
{
	int	i;

	sort_3_descending(b);
	if (b->top->next->next->next->value <= upper - 2)
	{
		i = 4;
		while (i--)
			pop_and_push(b, a);
		if (a->top->value > a->top->next->value)
			swap(a);
	}
	else if (b->top->next->next->next->value == upper - 1)
	{
		pop_and_push(b, a);
		pop_and_push(b, a);
		swap(b);
		pop_and_push(b, a);
		swap(a);
		pop_and_push(b, a);
	}
	else if (b->top->next->next->next->value == upper)
	{
		i = 3;
		while (i--)
			reverse_rotate(b);
		pop_and_push(b, a);
		i = 3;
		while (i--)
		{
			rotate(b);
			pop_and_push(b, a);
		}
	}
	return (-1);
}

//void	b_split(t_stack *a, t_stack *b, int lower, int upper);
// only subtract  1, for b_split upper limit, if height is even
void	b_split(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const bool	height_is_uneven = height % 2;
	int	pushed;

	// flush_queue(b->queue);
	// print_lst(b->top);
	// printf(" %i %i h%i\n", upper, lower, height);
	if (height == 0 || height == 4)
	{
//		printf("height b : %i ", height);
		// order_for_height_4(b, a, upper);
		// return ;
	}
	if (height <= 3)
	{
		if (height == 2 && b->top->value < b->top->next->value)
			swap(b);
		else if (lst_len(b->top) == 3)
			sort_bottom_3_descending(b);
		else if (height == 3)
			sort_3_descending(b);
		while ((upper-- - lower) + 1 > 0)
			pop_and_push(b, a);
		return ;
	}
	pushed = split_at_median(b, a, lower, upper);
	if (pushed == -1)
		return ;
	if (lower != 1 && lower != 2) //???
		unrotate_nodes(b, lower, lower + pushed - (!height_is_uneven));
	a_split(a, b, (upper - pushed) + 1, upper);
	b_split(a , b, lower, lower + pushed - (!height_is_uneven));
}

void	a_split(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	const bool	height_is_uneven = height % 2;
	int	pushed;
	//
	// flush_queue(b->queue);
	// print_lst(a->top);
	// printf(" %i %i h%i\n", upper, lower, height);
	if (ordered_ascending(a->top, lower, upper))
		return ;
	if (height <= 3)
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else if (height == 3)
			sort_3_ascending(a);
		return ;
	}
	pushed = split_at_median(a, b, lower, upper);
	unrotate_nodes(a, upper - pushed + 1 + height_is_uneven, upper);
	lower += pushed;
	a_split(a, b, lower, upper);
	b_split(a, b, lower - pushed, lower - 1);
}

void	intial_split_up_a(t_stack *a, t_stack *b, int lower, int upper)
{
	const int	height = (upper - lower) + 1;
	const int	median = (upper + lower) / 2;
	int	pushed;

	if (ordered_ascending(a->top, lower, upper))
		return ;
	if (height <= 3)
	{
		if (height == 2 && a->top->value > a->top->next->value)
			swap(a);
		else if (lst_len(a->top) == 3)
			sort_bottom_3_ascending(a);
		else if (height == 3)
			sort_3_ascending(a);
	}
	else
	{
		pushed = split_at_median(a, b, lower, upper);
		lower += pushed;
		intial_split_up_a(a, b, lower, upper);
		b_split(a, b, lower - pushed, lower - 1);
	}
}

// argc does not equate to the height since input can be in quotes, thus lst_len
void	*sort_stack(t_stack *a, t_stack *b)
{
	const int	height = lst_len(a->top);
	int   ordered;

	if (height < 2)
		return (NULL);
	intial_split_up_a(a, b, 1, height);
	return (NULL);
}
