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
