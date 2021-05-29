/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_while_rem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 17:43:48 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 17:52:12 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	push_while_rem(t_pswap *ps)
{
	while (ps->remaining && ps->stacks_bij.a &&
			int_at(ps->stacks_bij.a) == int_at(ps->remaining))
		ps_push_ab(ps, 1);
}
