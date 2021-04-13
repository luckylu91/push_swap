/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 02:59:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 15:20:11 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ps_swap_ab(t_pswap *ps, int op_code)
{
	swap_ab(&ps->stacks, op_code);
	swap_ab(&ps->stacks_bij, op_code);
}
