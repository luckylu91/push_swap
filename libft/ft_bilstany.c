/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstany.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:31:57 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 10:31:10 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_bilstany(t_bilist *blst, void *arg, t_bool_fun booleval)
{
	while (blst)
	{
		if ((*booleval)(blst->content, arg))
			return (1);
		blst = blst->next;
	}
	return (0);
}
