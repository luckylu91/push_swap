/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 16:32:00 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 15:18:35 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ps_push_ab(t_pswap *ps, int op_code)
{
	push_ab(&ps->stacks, op_code);
	push_ab(&ps->stacks_bij, op_code);
}
