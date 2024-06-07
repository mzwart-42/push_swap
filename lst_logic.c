#include "push_swap.h"

void		lst_push(t_node **lst, t_node *pushed_node)
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
	int	height;
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

void	print_lst(t_node	*lst)
{
	while (lst != NULL)	
	{
		printf(" %i -", lst->value);
		lst = lst->next;
	}
	printf(">\n");
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

