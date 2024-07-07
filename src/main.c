/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:30:01 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:30:45 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

// Pretty much all functions where something can malloc fail will use error_exit
void	error_exit(void)
{
	write(2, "Error\n", 6);
	exit(-1);
}

// if only you could have multiple assignment on one line...
void	init_stacks(t_stack *a, t_stack *b, t_queue *stack_operations)
{
	a->name = 'a';
	b->name = 'b';
	a->top = NULL;
	b->top = NULL;
	a->bottom = NULL;
	b->bottom = NULL;
	stack_operations->head = NULL;
	stack_operations->tail = NULL;
	a->queue = stack_operations;
	b->queue = stack_operations;
	a->other_stack = b;
	b->other_stack = a;
}

int	main(int argc, char **argv)
{
	int		height;
	t_queue	stack_operations;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	init_stacks(&a, &b, &stack_operations);
	if (argc == 2 && ft_strchr(argv[1], ' '))
		split_quoted_argv_and_parse(argv[1], &a);
	else
	{
		parse_cmd_args(argc - 1, argv + 1);
		push_cmd_args_on_stack(argc - 1, argv + 1, &a);
	}
	lst_map_values_to_indexes(a.top);
	height = lst_len(a.top);
	if (height > 1 && !ordered_ascending(a.top, 1, height))
		sort_stack(&a, &b, height);
	print_queued_operations(&stack_operations);
	lst_clear(&a.top);
}
