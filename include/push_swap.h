/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:07:45 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 11:09:26 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <stdbool.h>
# include <unistd.h>
# include <stddef.h>
# include <limits.h> // used for ft_strtoi, move this to libft later
# include <stddef.h>
# include <stdlib.h> //free

struct s_list_item
{
	int	value;
	struct s_list_item	*next;
};

typedef struct s_list_item	t_node;

typedef struct s_linked_list
{
	t_node	*head;
}	t_linked_list;


struct s_list_with_tail
{
	t_node	*head;
	t_node	*tail;
};
typedef struct s_list_with_tail t_queue;

// the stack holding a pointer to other_stack is kind of bad
typedef struct s_stack		t_stack_ptr;
typedef struct s_stack
{
	char		name;
	t_node		*top;
	t_node		*bottom;
	t_queue		*queue;
	t_stack_ptr	*other_stack;
}	t_stack;

enum e_operations
{
	sa,
	ra,
	rra,
	pb,
	sb,
	rb,
	rrb,
	pa,
	ss,
	rr,
	rrr
};

//----------------------------------------------------------------------------//
// main
void	error_exit(void);

//parse
bool	parse_cmd_args(int argc, char **argv);
t_stack	*push_cmd_args_on_stack(int argc, char **argv, t_stack *stack);
bool	split_quoted_argv_and_parse(char *quoted_arguments, t_stack *a);

// lst_utils (the lst 
void	lst_push(t_node **lst, t_node *pushed_node);
t_node	*lst_pop(t_node **lst);
void	lst_clear(t_node **lst);
void	print_lst(t_node *lst);
int		lst_len(t_node *lst);

// stack_utils
void	push(t_stack *stack, t_node *pushed_node);
void	print_two_stacks(const t_stack *first, const t_stack *second);
t_node	*create_node(int value);
t_node	*pop(t_stack *stack);

// split_stack
int		split_at_median(t_stack *stack, int lower, int upper);
int		split_into_three_chunks(t_stack *a, t_stack *b, int height);

// stack ops
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	pop_and_push(t_stack *src_stack, t_stack *dest_stack);
//map idexes
t_node	*lst_map_values_to_indexes(t_node *lst);

// sorting
void	start_split_or_sort_a(t_stack *a, t_stack *b, int lower, int upper);
void	sort_stack(t_stack *a, t_stack *b, int height);

// sorting utils
int		unrotate_nodes(t_stack *stack, int lower, int upper);
int		ordered_ascending(t_node *lst, int start, int end);
int		ordered_descending(t_node *lst, int start, int end);
int		consecutive_nodes_in_range(t_stack *stack, int lower, int upper);

// sort subset
void	sort_bottom_3_ascending(t_stack *stack);
void	sort_bottom_3_descending(t_stack *stack);
void	sort_3_ascending(t_stack *stack);
void	sort_3_descending(t_stack *stack);

// queue
void	enqueue(t_queue *q, t_node *new_node);
void	print_queued_operations(t_queue *ops);
void	flush_queue(t_queue *q);
void	ft_lstdel_one(t_node **head, t_node *node_to_remove);

// more queue optimize stuff
bool	opposite_stack(t_node *op1, t_node *op2);
bool	matching_operations(t_node *op1, t_node *op2);

t_node	*cancel_out_rotations(t_queue *ops, t_node *start, t_node *end);
t_node	*cancel_out_next_rotations(t_queue *ops, t_node *start, t_node *end);
t_node	*replace_top_with_double(t_queue *ops, t_node *start, t_node *end);
t_node	*insert_double_op_ahead(t_queue *ops, t_node *start, t_node *end);
void	lst_iter_and_optimize(t_queue *ops,
			t_node *(*optimize_fn)(t_queue *ops, t_node *top, t_node *end));
#endif
