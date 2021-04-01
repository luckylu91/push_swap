/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_permut.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 08:24:36 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 08:29:38 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

t_permut	*create_permut(int n)
{
	t_permut *permut;

	permut = ft_calloc(1, sizeof(t_permut));
	if (!permut)
		return (NULL);
	permut->n = n;
	permut->array = malloc(n * sizeof(int));
	permut->bijection = malloc(n * sizeof(int));
	if (!permut->array || !permut->bijection)
	{
		destroy_permut(permut);
		return (NULL);
	}
	return (permut);
}
