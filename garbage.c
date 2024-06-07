
int	round_up(float input)
{
	int	temp;

	temp = input;
	if ((float)temp != input)
		return ((int)input + 1);
	else
		return (input);
}

void	*split_stack_a(t_stack *a, t_stack *b, int lower, int upper)
{
	t_node	*boundries;
	t_node	*new;

	int	height = upper - lower + 1;
	boundries = NULL;
	while (height > 3)
	{
		//(a, b);
		lower += split_at_median(a, b, lower, upper);
		height = upper - lower + 1;
		//(a, b);
		new = create_node(lower - 1);
		if (!new)
			return (NULL);
		lst_push(&boundries, new);
	}
	sort_bottom_3_ascending(a);
	return (boundries);
}

void	print_array(void *array, size_t elem_size, size_t n)
{
	char	*specifier;
	size_t idx;

	idx = 0;
	while (idx < n)
	{
		if (elem_size == 4)
			printf("%i ", *((int *)array));
		else if (elem_size == 1)
			printf("%c ", *((int *)array));
		idx++;
		array += elem_size;
	}
	printf("\n");
}

void	push_b_on_a(t_stack *a, t_stack *b, t_node *medians)
{
	int	biggest;
	int	next_median;
	
	next_median = -1;
	while (medians != NULL)
	{
		if (medians->next)
			next_median = medians->next->value;
		biggest = medians->value;
		free(lst_pop(&medians));
		while (biggest > next_median)
		{
			surface_node(b, biggest);
			pop_and_push(b, a);
			biggest--;
		}
	}

}

int	int_max(int x, int y)
{
	if (x > y)
		return (x);
	else
		return (y);
}



// rounds up the result
int	int_log2(int input)
{
	float	result;

	result = 0;
	while (input >= 2)
	{
		input /= 2;
		result++;
	}
	return (result + 1);
}


int	surface_node(t_stack *stack, int val)
{
	int	nodes_rotated;

	nodes_rotated = 0;
	while (stack->top->value != val)
	{
		if (stack->top->next->value == val)
		{
			swap(stack);
			break;
		}
		rotate(stack);
		nodes_rotated++;
	}
	return (nodes_rotated);
}


int	stack_nodes_ordered(t_stack *stack)
{
	int	count;
	t_node	*traverse;

	count = 0;
	traverse = stack->top;
	while (traverse && traverse->value + 1 == traverse->next->value)
	{
		count++;
		traverse = traverse->next;
	}
	return (count);
}

