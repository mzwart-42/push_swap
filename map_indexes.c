#include "push_swap.h"

// shit this uuuu ugly
static void sorted_insertion(t_node **head, t_node *inserted_node)
{	
	t_node	*lst;

	if (inserted_node->value < (*head)->value)
	{
		inserted_node->next = *head;	
		*head = inserted_node;
		return ;
	}
	lst = *head;
	while (lst->next != NULL && lst->next->value < inserted_node->value)
		lst = lst->next;
	inserted_node->next = lst->next;
	lst->next = inserted_node;
}

static t_node	*create_ordered_set(t_node *lst)
{
	t_node	*ordered_set;
	t_node	*new_node;

	ordered_set = NULL;
	while (lst != NULL)
	{	
		new_node = create_node(lst->value);
		if (!new_node)
		{
			lst_clear(&ordered_set);
			return (NULL);
		}
		if (ordered_set == NULL)
			ordered_set = new_node;
		else
			sorted_insertion(&ordered_set, new_node);
		lst = lst->next;
	}
	return (ordered_set);
}

ssize_t	lst_search_len(t_node *lst, int searched_int)
{
	size_t	nodes_traversed;

	nodes_traversed = 0;
	while (lst != NULL && lst->value != searched_int)
	{
		lst = lst->next;
		nodes_traversed++;
	}
	if (lst != NULL)
		return (nodes_traversed);
	return (-1);
}

t_node	*lst_map_values_to_indexes(t_node *lst_to_be_mapped)
{
	t_node	*set;
	t_node	*unmapped_lst;
	size_t	set_index;

	set = create_ordered_set(lst_to_be_mapped);
	if (!set)
	{
		lst_clear(&lst_to_be_mapped);
		error_exit();
	}
	unmapped_lst = lst_to_be_mapped;
	while (unmapped_lst != NULL)
	{
		set_index = lst_search_len(set, unmapped_lst->value);
		unmapped_lst->value = set_index + 1;
		unmapped_lst = unmapped_lst->next;
	}
	lst_clear(&set);
	return (lst_to_be_mapped);
}
