/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/18 16:32:34 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 11:15:24 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

int	int_at(t_bilist *lst)
{
	return (*(int*)lst->content);
}

char	op_last_char(char op_char, int op_code)
{
	if (op_code == 0)
		return ('a');
	else if (op_code == 1)
		return ('b');
	else
		return (op_char);
}

void	swap_int(int *n, int *p)
{
	int	tmp;

	tmp = *n;
	*n = *p;
	*p = tmp;
}
