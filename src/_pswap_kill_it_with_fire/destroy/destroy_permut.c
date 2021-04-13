/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_permut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:23:37 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 11:16:52 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_permut(t_permut **permut_ptr)
{
	int			i;
	t_permut	*permut;

	permut = *permut_ptr;
	if (!permut)
		return ;
	free(permut->array);
	free(permut->array_trans);
	free(permut->trans_indices);
	free(permut->val_indices);
	free(permut->bijection);
	if (permut->paths)
	{
		i = 0;
		while (i < permut->n)
		{
			destroy_pathinfo(&permut->paths[i]);
			i++;
		}
		free(permut->paths);
	}
	free(permut);
	*permut = NULL;
}
