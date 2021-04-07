/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_indices.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:50:28 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 16:52:18 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	compute_indices(t_permut *permut)
{
	int i;

	i = 0;
	while (i < permut->n)
	{
		permut->val_indices[permut->array_trans[i]] = i;
		i++;
	}
}
