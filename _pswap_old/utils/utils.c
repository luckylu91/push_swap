/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 11:58:52 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 20:43:08 by lzins            ###   ########lyon.fr   */
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
