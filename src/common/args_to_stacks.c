/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 13:43:38 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	arg_is_valid(char *arg)
{
	int offset;

	offset = 0;
	if (*arg == '+' || *arg == '-')
		offset++;
	return (ft_all_in(arg + offset, "0123456789") && !ft_atoi_overflows(arg));
}

static int	array_to_stacks(t_stacks *stacks, int n, char **array)
{
	int i;

	stacks->n = n;
	stacks->a_size = n;
	stacks->b_size = 0;
	i = 0;
	while (i < n)
	{
		if (!arg_is_valid(array[i])
			|| ft_lstdupint_back(&stacks->a, ft_atoi(array[i])) == -1)
			return (error_free(stacks));
		i++;
	}
	return (1);
}

// TODO ne pas gere 1 argument
int	args_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int i_start;

	stacks->a = NULL;
	stacks->b = NULL;
	stacks->verbose = 0;
	if (argc == 1)
		return (-1);
	i_start = 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		i_start = 2;
		stacks->verbose = 1;
	}
	return (array_to_stacks(stacks, argc - (i_start), argv + i_start) == -1);
}
