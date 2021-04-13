/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:13:24 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 20:39:58 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_pathinfo(t_pathinfo *pi)
{
	if (!pi)
		return ;
	ft_lstclear(&pi->path, free);
	ft_lstclear(&pi->dists, free);
}
