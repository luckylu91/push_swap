/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_permut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:23:37 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 17:37:26 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_permut(t_permut *permut)
{
	int i;

	if (!permut)
		return ;
	free(permut->array);
	free(permut->array_trans);
	free(permut->trans_indices);
	free(permut->val_indices);
	free(permut->bijection);
	i = 0;
	while (i < permut->n)
	{
		destroy_pathinfo(&permut->paths[i]);
		i++;
	}
	free(permut->paths);
	free(permut);
}
