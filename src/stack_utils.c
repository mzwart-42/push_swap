/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:27:19 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:27:49 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *stack, t_node *pushed_node)
{
	if (!stack->top)
		stack->bottom = pushed_node;
	pushed_node->next = stack->top;
	stack->top = pushed_node;
}

t_node	*pop(t_stack *stack)
{
	t_node	*popped_node;

	if (stack->top == stack->bottom)
		stack->bottom = NULL;
	popped_node = stack->top;
	stack->top = stack->top->next;
	popped_node->next = NULL;
	return (popped_node);
}

int	stack_height(t_stack *stack)
{
	int		height;
	t_node	*traverse_stack;

	height = 0;
	traverse_stack = stack->top;
	while (traverse_stack)
	{
		traverse_stack = traverse_stack->next;
		height = 0;
	}
	return (height);
}
//
// // used for debugging
// void	print_lst(t_node *lst)
// {
// 	while (lst != NULL)
// 	{
// 		ft_printf(" %i -", lst->value);
// 		lst = lst->next;
// 	}
// 	ft_printf(">\n");
// }
//
// // same
// void	print_two_stacks(const t_stack *first, const t_stack *second_stack)
// {
// 	ft_printf("\n============\n");
// 	ft_printf(" stack A: \n");
// 	if (first)
// 		print_lst(first->top);
// 	ft_printf(" stack B: \n");
// 	if (second_stack)
// 		print_lst(second_stack->top);
// 	ft_printf("============\n");
// }
