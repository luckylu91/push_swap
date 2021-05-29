/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:30:02 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	arg_is_valid(char *arg)
{
	int offset;

	offset = 0;
	if (*arg == '+' || *arg == '-')
		offset++;
	return (arg[offset]
		&& ft_all_in(arg + offset, "0123456789")
		&& !ft_atoi_overflows(arg));
}

static int	array_to_stacks(t_stacks *stacks, int n, char **array)
{
	int i;

	stacks->n = n;
	i = 0;
	while (i < n)
	{
		if (!arg_is_valid(array[i]))
			return (1);
		addback_int(stacks->a, ft_atoi(array[i]));
		i++;
	}
	return (0);
}

int	args_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i_start;

	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_sorted = NULL;
	stacks->b_sorted = NULL;
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
	if (ft_any(argv + i_start, argc - i_start))
	if (array_to_stacks(stacks, argc - i_start, argv + i_start))
		return (1);
	sort_bilist(stacks->a, &stacks->a_sorted);
	return (0);
}
