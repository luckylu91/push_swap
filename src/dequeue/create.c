/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:29:21 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:34:32 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap_recursion.h"

t_dequeue	*new_dequeue(void)
{
	t_dequeue	*q;

	q = ft_calloc(1, sizeof(t_dequeue));
	q->first = NULL;
	q->last = NULL;
	q->size = 0;
	return (q);
}
