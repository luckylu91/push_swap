/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/13 18:31:25 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_swap_ab(t_stacks *stacks, int op_code)
{
	swap_ab(stacks, op_code);
	ft_putstr_fd("s", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('s', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	//
	print_stacks_side(stacks);
}
