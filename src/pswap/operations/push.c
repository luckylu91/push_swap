/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:53:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_push_ab(t_pswap *ps, int op_code)
{
	int	k;

	if (op_code == 1)
	{
		k = int_at(ps->stacks_bij.a);
		free(ft_lstremove(&ps->remaining, &k, sizeof(int)));
	}
	push_ab(&ps->stacks_init, op_code);
	push_ab(&ps->stacks_bij, op_code);
	if (op_code == 0)
		ft_putendl_fd("pa", STDOUT_FILENO);
	else if (op_code == 1)
		ft_putendl_fd("pb", STDOUT_FILENO);
	if (ps->stacks_init.verbose)
		print_stacks_side(&ps->stacks_init);
}
