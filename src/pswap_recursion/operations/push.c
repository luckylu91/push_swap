/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 14:46:08 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

void	ps_push_ab(t_stacks *stacks, int op_code)
{
	push_ab(stacks, op_code);
	ft_putstr_fd("p", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('p', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (stacks->verbose)
		print_stacks(stacks);
}

void	ps_push_n(t_stacks *s, int op_code, int n)
{
	while (n-- > 0)
	{
		ps_push_ab(s, op_code);
	}
}
