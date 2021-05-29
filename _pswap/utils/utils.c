/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:58:52 by lzins             #+#    #+#             */
/*   Updated: 2021/05/18 10:46:48 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	int_at(t_list *lst)
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
