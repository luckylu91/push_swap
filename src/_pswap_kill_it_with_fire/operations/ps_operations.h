/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:40:19 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 16:43:33 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ps_nrotate_ab(t_pswap *ps, int n, int op_code)
{
	if (n > 0)
	{
		while (n > 0)
		{
			ps_rotate_ab(ps, op_code);
			n--;
		}
	}
	else if (n < 0)
	{
		while (n < 0)
		{
			ps_rotate_reverse_ab(ps, op_code);
			n++;
		}
	}
}
