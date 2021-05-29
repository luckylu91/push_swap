/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 13:18:44 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
//
#include <stdio.h>

static int	arg_is_valid(char *arg)
{
	int offset;

	offset = 0;
	if (*arg == '+' || *arg == '-')
		offset++;
	return (arg[offset] && ft_all_in(arg + offset, "0123456789")
		&& !ft_atoi_overflows(arg));
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
		if (!arg_is_valid(array[i]))
			return (1);
		ft_lstdupint_back(&stacks->a, ft_atoi(array[i]));
		i++;
	}
	return (0);
}

static t_bilist	*lstinsert_sorted(t_bilist *lst_sorted, t_bilist *new_elem)
{
	t_bilist	*tail;

	if (!lst_sorted)
		return (new_elem);
	if (int_at(lst_sorted) < int_at(new_elem))
	{
		tail = lstinsert_sorted(lst_sorted->next, new_elem);
		lst_sorted->next = tail;
		tail->prev = lst_sorted;
		return (lst_sorted);
	}
	else
	{
		new_elem->next = lst_sorted;
		lst_sorted->prev = new_elem;
		return (new_elem);
	}
}

static void	lstdupint_sorted(t_bilist **lst_sorted, int k)
{
	t_bilist	*new_elem;

	new_elem = NULL;
	ft_bilstdupint_back(&new_elem, k);
	*lst_sorted = lstinsert_sorted(*lst_sorted, new_elem);
}

static void	sort_bilist(t_bilist *lst, t_bilist **lst_sorted)
{
	while (lst)
	{
		lstdupint_sorted(lst_sorted, int_at(lst));
		lst = lst->next;
	}
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
	if (array_to_stacks(stacks, argc - i_start, argv + i_start))
		return (1);
	sort_bilist(stacks->a, &stacks->a_sorted);
	return (0);
}
