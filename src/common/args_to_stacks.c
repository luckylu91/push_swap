/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 03:29:31 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "dequeue.h"

static int	arg_is_invalid(char **arg_ptr)
{
	int		offset;
	char	*arg;

	arg = *arg_ptr;
	offset = 0;
	if (*arg == '+' || *arg == '-')
		offset++;
	// if (ft_atoi_overflows(arg))
	// 	printf("Argument is not an int (overflow): %s\n", arg);
	// if(!arg[offset] || !ft_all_in(arg + offset, "0123456789"))
	// 	printf("Argument is not numeric: %s\n", arg);
	return (!arg[offset]
		|| !ft_all_in(arg + offset, "0123456789")
		|| ft_atoi_overflows(arg));
}

static void	array_to_stacks(t_stacks *stacks, int n, char **array)
{
	int i;

	stacks->n = n;
	i = 0;
	while (i < n)
	{
		// if (!arg_is_valid(array[i]))
		// 	return (1);
		addback_int(stacks->a, ft_atoi(array[i]));
		i++;
	}
}

int	args_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i_start;

	stacks->a = new_dequeue();
	stacks->b = new_dequeue();
	stacks->verbose = 0;
	if (argc == 1)
		return (0);
	i_start = 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		if (argc == 2)
			return (0);
		i_start = 2;
		stacks->verbose = 1;
	}
	if (ft_any(argv + i_start, argc - i_start, sizeof(char*), (t_bool_fun)arg_is_invalid))
		return (1);
	array_to_stacks(stacks, argc - i_start, argv + i_start);
	stacks->a_sorted = sorted_queue(stacks->a);
	// printf("a_sorted : ");
	// print_queue(stacks->a_sorted, " ", "\n");
	return (0);
}
