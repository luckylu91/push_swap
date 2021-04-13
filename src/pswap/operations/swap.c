/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:44:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_swap_ab(t_pswap *ps, int op_code)
{
	swap_ab(&ps->stacks_init, op_code);
	swap_ab(&ps->stacks_bij, op_code);
	if (op_code == 0)
		ft_putendl_fd("sa", STDOUT_FILENO);
	else if (op_code == 1)
		ft_putendl_fd("sb", STDOUT_FILENO);
	else if (op_code == 2)
		ft_putendl_fd("ss", STDOUT_FILENO);
	if (ps->stacks_init.verbose)
		print_stacks_side(&ps->stacks_init);
}
