/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_reverse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 03:09:03 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 15:19:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	ps_rotate_reverse_ab(t_pswap *ps, int op_code)
{
	rotate_reverse_ab(&ps->stacks, op_code);
	rotate_reverse_ab(&ps->stacks_bij, op_code);
}
