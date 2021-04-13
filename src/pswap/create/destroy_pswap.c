/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_pswap.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 11:19:07 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 11:36:30 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_pswap(t_pswap **pswap_ptr)
{
	t_pswap *ps;

	ps;
	if (!ps)
		return ;
	free(ps->stacks_init);
	free(ps->stacks_bij);
	destroy_permut(&ps->permut);
	free(ps->path_array);
	free(ps->remaining_array);
	free(ps->spots_left);
	free(ps->spots_right);
	free(ps);
	*pswap_ptr = NULL;
}
