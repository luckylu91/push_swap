/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/04/13 18:31:09 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_push_ab(t_stacks *stacks, int op_code)
{
	push_ab(stacks, op_code);
	ft_putstr_fd("p", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('p', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	//
	print_stacks_side(stacks);
}
