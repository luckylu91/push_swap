/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ok.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 10:48:43 by lzins             #+#    #+#             */
/*   Updated: 2021/06/05 09:33:09 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int	ok_message(void)
{
	ft_putendl_fd("OK", STDOUT_FILENO);
	return (0);
}

static int	ko_message(void)
{
	ft_putendl_fd("KO", STDOUT_FILENO);
	return (1);
}

int	check_ok(t_stacks *stacks)
{
	int			k1;
	int			k2;
	t_bilist	*a;

	if (stacks->b->size != 0)
		return (ko_message());
	if (stacks->a->size <= 1)
		return (ok_message());
	k1 = int_at(stacks->a->first);
	a = stacks->a->first->next;
	while (a)
	{
		k2 = int_at(a);
		if (k1 >= k2)
			return (ko_message());
		k1 = k2;
		a = a->next;
	}
	return (ok_message());
}
