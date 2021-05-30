/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 14:46:28 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

void	ps_rotate_reverse_ab(t_stacks *stacks, int op_code)
{
	rotate_reverse_ab(stacks, op_code);
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('r', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (stacks->verbose)
		print_stacks(stacks);
}

void	ps_rotate_reverse_n(t_stacks *s, int op_code, int n)
{
	while (n-- > 0)
	{
		ps_rotate_reverse_ab(s, op_code);
	}
}

