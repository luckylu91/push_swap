/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bilist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 16:59:34 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 17:06:53 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

void	*itoa_ptr(void *iptr)
{
	if (iptr)
		return (ft_itoa(*(int*)iptr));
	else
		return (NULL);
}

void	print_bilist(t_bilist *lst_int)
{
	t_bilist	*lst_str;
	char	*res_str;

	lst_str = ft_lstmap(lst_int, itoa_ptr, free);
	if (!lst_str)
		return ;
	res_str = ft_lststrjoin(lst_str, ", ", "[", "]");
	if (res_str)
	{
		ft_putstr_fd(res_str, STDOUT_FILENO);
		free(res_str);
	}
	ft_lstclear(&lst_str, free);
}
