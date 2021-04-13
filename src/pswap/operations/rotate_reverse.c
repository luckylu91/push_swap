/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:44:28 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_rotate_reverse_ab(t_pswap *ps, int op_code)
{
	rotate_reverse_ab(&ps->stacks_init, op_code);
	rotate_reverse_ab(&ps->stacks_bij, op_code);
	if (op_code == 0)
		ft_putendl_fd("rra", STDOUT_FILENO);
	else if (op_code == 1)
		ft_putendl_fd("rrb", STDOUT_FILENO);
	else if (op_code == 2)
		ft_putendl_fd("rrr", STDOUT_FILENO);
	if (ps->stacks_init.verbose)
		print_stacks_side(&ps->stacks_init);
}
