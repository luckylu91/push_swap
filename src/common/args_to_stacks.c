/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_to_stacks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:30:58 by lzins             #+#    #+#             */
/*   Updated: 2021/05/18 16:47:49 by lzins            ###   ########lyon.fr   */
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
	return (arg[offset] && ft_all_in(arg + offset, "0123456789") && !ft_atoi_overflows(arg));
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

static t_list	*lstinsert_sorted(t_list *lst_sorted, t_list *new_elem)
{
	if (!lst_sorted)
		return (new_elem);
	if (int_at(lst_sorted) < int_at(new_elem))
	{
		lst_sorted->next = lstinsert_sorted(lst_sorted->next, new_elem);
		return (lst_sorted);
	}
	else
	{
		new_elem->next = lst_sorted;
		return (new_elem);
	}
}

static int	lstdupint_sorted(t_list **lst_sorted, int k)
{
	t_list	*new_elem;

	new_elem = NULL;
	if (ft_lstdupint_back(&new_elem, k) == -1)
		return (-1);
	*lst_sorted = lstinsert_sorted(*lst_sorted, new_elem);
	return (1);
}

static int	sort_list(t_list *lst, t_list **lst_sorted)
{
	while (lst)
	{
		if (lstdupint_sorted(lst_sorted, int_at(lst)))
		{
			ft_lstclear(lst_sorted, free);
			return (-1);
		}
		lst = lst->next;
	}
	return (1);
}

// TODO ne pas gere 1 argument
int	args_to_stacks(t_stacks *stacks, int argc, char **argv)
{
	int	i_start;
	int	ret;

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
	ret = array_to_stacks(stacks, argc - i_start, argv + i_start);
	if (ret >= 0)
		ret = sort_list(stacks->a, &stacks->a_sorted);
	return (ret);
}
