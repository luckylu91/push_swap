/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groupstacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 12:48:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/17 13:22:34 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static int	add_two_ones(t_list **glst, int n)
{
	int	ret;

	ret = 1;
	while (n > 0 && ret >= 0)
	{
		ret = ft_lstdupint_back(glst, 1);
		n--;
	}
	return (ret);
}

static int	add_group_size(t_list **glst, int group_size)
{
	if (group_size <= 2 && add_ones(glst, group_size) == -1)
		return (-1);
	else if (group_size > 2 && ft_lstdupint_back(glst, group_size) == -1)
		return (-1);
}

static t_list	*lstclear_error(t_list **glst)
{
	ft_lstclear(glst, free);
	return (NULL);
}

t_list		*grouplist(t_list *lst)
{
	int		k;
	int		k_next;
	int		group_size;
	t_list	*glst;

	if (!lst)
		return (NULL);
	group_size = 1;
	k = int_at(lst);
	while (lst->next)
	{
		k_next = int_at(lst->next);
		if (k < k_next)
			group_size++;
		else if (add_group_size(&glst, group_size) == -1)
			return (lstclear_error(&glst));
		else
			group_size = 1;
		k = k_next;
		lst = lst->next;
	}
	if (add_group_size(&glst, group_size) == -1)
		return (lstclear_error(&glst));
	return (glst);
}

t_stacks	*groupstacks(t_stacks *stacks)
{
	t_stacks	*gstacks;
	int			ret;

	gstacks = ft_calloc(1, sizeof(t_stacks));
	if (!gstacks)
		return (NULL);
	gstacks->a = grouplist(stacks->a);
	gstacks->b = grouplist(stacks->b);
	if ((stacks->a && !gstacks->a) || (stacks->b && !gstacks->b))
	{
		free_stacks(gstacks);
		return (NULL);
	}
	gstacks->a_size = ft_lstsize(gstacks->a);
	gstacks->b_size = ft_lstsize(gstacks->b);
	gstacks->n = gstacks->a_size + gstacks->b_size;
	gstacks->verbose = 0;
	return (gstacks);
}
