/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:32:02 by lzins            ###   ########lyon.fr   */
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

static int	array_to_list(t_stacks *stacks, char **array)
{
	int i;

	i = 0;
	while (i < stacks->n)
	{
		if (!arg_is_valid(array[i])
			|| ft_lstdupint_back(&stacks->a, ft_atoi(array[i])) == -1)
			return (error_free(stacks));
		i++;
	}
	return (1);
}

static int	args_to_list(t_stacks *stacks, int n, char **argv_shifted)
{
	char	**splitted;
	int	ret;

	splitted = NULL;
	if (n == 0)
		return (error());
	if (n == 1)
	{ // ....pas besoin
		splitted = ft_split(argv_shifted[0], " ");
		if (!splitted)
			return (error());
		stacks->n = ft_splitlen(splitted);
		ret = array_to_list(stacks, splitted);
		ft_arrayclear((void**)splitted, stacks->n);
	}
	else
	{
		stacks->n = n;
		ret = array_to_list(stacks, argv_shifted);
	}
	stacks->a_size = stacks->n;
	return (ret);
}

// TODO ne pas gere 1 argument
int	args_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int i_start;

	stacks->a = NULL;
	stacks->b = NULL;
	stacks->a_size = 0;
	stacks->b_size = 0;
	stacks->verbose = 0;
	if (argc == 1)
		return (-1);
	i_start = 1;
	if (ft_strcmp(argv[1], "-v") == 0)
	{
		i_start = 2;
		stacks->verbose = 1;
	}
	return (args_to_list(stacks, argc - (i_start), argv + i_start));
}
