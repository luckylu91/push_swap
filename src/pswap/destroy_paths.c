/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/07 16:13:24 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 17:36:56 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	destroy_pathinfo(t_pathinfo *pi)
{
	ft_lstclear(&pi->path, free);
	ft_lstclear(&pi->dists, free);
}