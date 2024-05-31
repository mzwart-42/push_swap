#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h> // remove later?

extern int	exec_cost;

typedef struct s_int_list t_node;
typedef struct s_int_list
{
  t_node	*next;
  int		value;
} t_int_list;

typedef struct s_stack t_queue;
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	t_queue	*queue;
	char		name;
}	t_stack;

//enum operations {sa, sb, ss, ra, rb, rr, pa, pb, pp, rra, rrb, rrr};
enum e_operations {swap_stack, rotate_stack, reverse_rotate_stack, pop_and_push_stack};

// stack logic
void	push(t_stack *stack, t_node *pushed_node);
void	print_two_stacks(const t_stack *first_stack, const t_stack *second_stack);
t_node	*create_node(int value);
t_node	*pop(t_stack *stack);

// code obfuscation ?
#define	DEQUEUE(queue) pop(queue)

// stack operations
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);
void	pop_and_push(t_stack *src_stack, t_stack *dest_stack);

// lst logic
void	lst_push(t_node **lst, t_node *pushed_node);
t_node	*lst_pop(t_node **lst);
void	lst_clear(t_node **lst);
void	print_lst(t_node *lst);

//map idexes
t_node	*lst_map_values_to_indexes(t_node *lst);
//ssize_t	count_nodes_searched(t_node *lst, int searched_int);

// sorting
void	*sort_stack(t_stack *a, t_stack *b, int height_a);
int	ordered_ascending(t_stack *stack, int lower);
int	ordered_descending(t_stack *stack, int upper);
//int	split_at_median(t_stack *src_stack, t_stack *dest_stack, int lower, int upper);
//int	split_at_median(t_stack *src, t_stack *dest, \
	int(*f)(t_stack *, t_stack *, int), int lower, int upper);

// sort subset
void	sort_bottom_3_ascending(t_stack *stack);
void	sort_bottom_3_descending(t_stack *stack);

// sorting utils
void	sort_3_ascending(t_stack *stack);
void	sort_3_descending(t_stack *stack);
int	unrotate_nodes(t_stack *stack, int lower, int upper);


int	lst_len(t_node *lst);

// queue
void	enqueue(t_queue *q, t_node *new_node);

//void	sort_single_stack(t_stack *stack);
