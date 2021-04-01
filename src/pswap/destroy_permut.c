/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_permut.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:23:37 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:30:25 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_permut(t_permut *permut)
{
	if (!permut)
		return ;
	free(permut->array);
	free(permut->bijection);
	free(permut);
}
