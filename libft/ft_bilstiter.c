/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:27:33 by lzins             #+#    #+#             */
/*   Updated: 2021/05/30 10:29:00 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bilstiter(t_bilist *lst, void *arg, t_fun f)
{
	while (lst != NULL)
	{
		(*f)(lst->content, arg);
		lst = lst->next;
	}
}
