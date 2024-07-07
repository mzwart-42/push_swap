/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:51:26 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:51:26 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	lst_push(t_node **lst, t_node *pushed_node)
{
	if (pushed_node == NULL)
		return ;
	pushed_node->next = *lst;
	*lst = pushed_node;
}

t_node	*lst_pop(t_node **lst)
{
	t_node	*popped_node;

	if (lst == NULL || *lst == NULL)
		return (NULL);
	popped_node = *lst;
	*lst = (*lst)->next;
	popped_node->next = NULL;
	return (popped_node);
}

int	lst_len(t_node *lst)
{
	int		height;
	t_node	*traverse;

	height = 0;
	traverse = lst;
	while (traverse)
	{
		traverse = traverse->next;
		height++;
	}
	return (height);
}

void	lst_clear(t_node **lst)
{
	t_node	*current_node;
	t_node	*tmp_for_free;

	current_node = *lst;
	while (current_node != NULL)
	{
		tmp_for_free = current_node;
		current_node = (current_node)->next;
		free(tmp_for_free);
	}
	*lst = NULL;
}

t_node	*create_node(int value)
{
	t_node	*new_node;

	new_node = malloc(sizeof(t_node));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->next = NULL;
	return (new_node);
}
