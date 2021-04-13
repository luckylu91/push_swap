/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:04:25 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:44:17 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_rotate_ab(t_pswap *ps, int op_code)
{
	rotate_ab(&ps->stacks_init, op_code);
	rotate_ab(&ps->stacks_bij, op_code);
	if (op_code == 0)
		ft_putendl_fd("ra", STDOUT_FILENO);
	else if (op_code == 1)
		ft_putendl_fd("rb", STDOUT_FILENO);
	else if (op_code == 2)
		ft_putendl_fd("rr", STDOUT_FILENO);
	if (ps->stacks_init.verbose)
		print_stacks_side(&ps->stacks_init);
}
