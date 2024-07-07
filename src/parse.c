/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzwart <mzwart@student.codam.nl>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 10:52:15 by mzwart            #+#    #+#             */
/*   Updated: 2024/06/22 10:57:28 by mzwart           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		s1++;
		s2++;
	}
	return (0);
}

int	ft_strtoi(const char *str, bool *succes)
{
	int			character;
	int			result;
	bool		neg;

	*succes = 0;
	result = 0;
	neg = (*str == '-');
	str += neg;
	while (*str)
	{
		character = *str++;
		if (character >= '0' && character <= '9')
			character -= '0';
		else
			return (result);
		if (result > (INT_MAX / 10) || \
			(result == (INT_MAX / 10) && character > INT_MAX % 10 + neg))
			return (result);
		result *= 10;
		result += character;
	}
	*succes = 1;
	return (result * (-1 * neg));
}

bool	parse_cmd_args(int argc, char **argv)
{
	char	*arg;
	int		arg_idx;
	int		cmp_idx;
	bool	succes;

	arg_idx = 0;
	while (arg_idx < argc)
	{
		arg = argv[arg_idx];
		ft_strtoi(arg, &succes);
		if (!succes)
			error_exit();
		cmp_idx = 1;
		while (arg_idx + cmp_idx < argc)
		{
			if (ft_strcmp(argv[arg_idx], argv[arg_idx + cmp_idx]) == 0)
				error_exit();
			++cmp_idx;
		}
		++arg_idx;
	}
	return (0);
}

// make this into parse_str_arr instead of argv specific
t_stack	*push_cmd_args_on_stack(int argc, char **argv, t_stack *stack)
{
	t_node	*new_node;
	char	*arg;
	long	arg_to_long;

	while (argc > 0)
	{
		arg = argv[argc - 1];
		arg_to_long = atoi(arg);
		new_node = create_node((int)arg_to_long);
		if (!new_node)
			error_exit();
		push(stack, new_node);
		--argc;
	}
	return (stack);
}

bool	split_quoted_argv_and_parse(char *quoted_arguments, t_stack *a)
{
	char	**cmd_args;
	char	**traverse_args;
	int		arg_count;

	cmd_args = ft_split(quoted_arguments, ' ');
	if (!cmd_args)
		error_exit();
	arg_count = 0;
	traverse_args = cmd_args;
	while (*traverse_args++ != NULL)
		arg_count++;
	parse_cmd_args(arg_count, cmd_args);
	push_cmd_args_on_stack(arg_count, cmd_args, a);
	free(cmd_args);
	return (true);
}
