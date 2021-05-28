/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:04:25 by lzins             #+#    #+#             */
/*   Updated: 2021/05/18 12:04:13 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

void	ps_rotate_ab(t_stacks *stacks, int op_code)
{
	rotate_ab(stacks, op_code);
	ft_putstr_fd("r", STDOUT_FILENO);
	ft_putchar_fd(op_last_char('r', op_code), STDOUT_FILENO);
	ft_putchar_fd('\n', STDOUT_FILENO);
	if (stacks->verbose)
		print_stacks_side(stacks);
}
