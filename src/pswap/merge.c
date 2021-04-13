/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:32:53 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 22:41:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

//
#include <stdio.h>

void	merge_ab(t_stacks *stacks, int na, int nb, int op_code)
{
	int	n;
	int	i;

	n = na + nb;
	i = -1;
	while (++i < n)
	{
		if (int_at(stacks->a) > int_at(stacks->b))
			ps_push_ab(stacks, op_code);
		ps_rotate_ab(stacks, op_code);
	}
}

static void ps_nrotate_a(t_stacks *stacks, int n)
{
	while (n > 0)
	{
		ps_rotate_ab(stacks, 0);
		n--;
	}
}

void	merge_a2(t_stacks *stacks, int offset, int na2)
{
	t_list	*a2;
	int		a2_val;
	int		nb;

	if (na2 == 0)
	{
		ps_nrotate_a(stacks, offset);
		return ;
	}
	a2 = ft_lststep(stacks->a, offset);
	a2_val = int_at(a2);
	while (int_at(stacks->a) < a2_val)
	{
		ps_rotate_ab(stacks, 0);
		offset--;
	}
	nb = offset;
	while (offset > 0)
	{
		ps_push_ab(stacks, 1);
		offset--;
	}
	merge_ab(stacks, na2, nb, 0);
}
