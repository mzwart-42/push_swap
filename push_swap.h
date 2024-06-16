#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <stddef.h>

// DEBUGGING
#include <stdio.h> // remove later
#include <assert.h> // remove later
extern int	exec_cost;


typedef struct s_int_list t_node;
typedef struct s_int_list
{
  t_node	*next;
  int		value;
} t_int_list;

// this is garbage fml
typedef struct s_stack t_stack_ref;
typedef struct s_stack t_queue;
typedef struct s_stack
{
	t_node	*top;
	t_node	*bottom;
	t_queue	*queue;
	char		name;
	t_stack_ref	*other_stack_to_free;
}	t_stack;

enum operations {sa, ra, rra, pb, sb, rb, rrb, pa, ss, rr, rrr};

//enum e_operations {swap_, rotate_, reverse_rotate_, push_, switch_};

//----------------------------------------------------------------------------//

// main
void	error_exit();

//parse
bool		parse_cmd_args(int argc, char **argv);
t_stack	*push_cmd_args_on_stack(int argc, char **argv, t_stack *stack);
bool		split_quoted_argv_and_parse(char *quoted_arguments, t_stack *a);

// split
char		**ft_split(char const *str, char delimiter);




// stack logic
void	push(t_stack *stack, t_node *pushed_node);
void	print_two_stacks(const t_stack *first_stack, const t_stack *second_stack);
t_node	*create_node(int value);
t_node	*pop(t_stack *stack);

// split median
int	split_at_median(t_stack *src, t_stack *dest, int lower, int upper);

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
int	lst_len(t_node *lst);

//map idexes
t_node	*lst_map_values_to_indexes(t_node *lst);

// sorting
void	*sort_stack(t_stack *a, t_stack *b);

// sorting utils
int	unrotate_nodes(t_stack *stack, int lower, int upper);
int	ordered_ascending(t_node *lst, int start, int end);
int	ordered_descending(t_node *lst, int start, int end);
int	consecutive_nodes_in_range(t_stack *stack, int lower, int upper);

// sort subset
void	sort_bottom_3_ascending(t_stack *stack);
void	sort_bottom_3_descending(t_stack *stack);
void	sort_3_ascending(t_stack *stack);
void	sort_3_descending(t_stack *stack);

// queue
void	enqueue(t_queue *q, t_node *new_node);
void	print_queued_operations(t_queue *operations);
void	flush_queue(t_queue *q);
void	ft_lstdel_one(t_node **head, t_node *node_to_remove);

// code obfuscation ?
#define	DEQUEUE(queue) pop(queue)
