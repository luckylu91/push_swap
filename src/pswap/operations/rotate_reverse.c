/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/04/13 18:31:14 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_rotate_reverse_ab(t_stacks *stacks, int op_code)
{
	rotate_reverse_ab(stacks, op_code);
	ft_putstr_fd("rr", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('r', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	//
	print_stacks_side(stacks);
}
