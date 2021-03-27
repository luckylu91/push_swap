/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:14:05 by lzins             #+#    #+#             */
/*   Updated: 2021/03/27 13:54:11 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static int starts_with(char *str, char *prefix)
{
	size_t len_str;
	size_t len_prefix;

	len_str = ft_strlen(str);
	len_prefix = ft_strlen(prefix);
	if (len_str < len_prefix)
		return (0);
	return (ft_strncmp(prefix, str, len_prefix) == 0);
}

static int correct_cmd(char *str)
{

}

int	parse_operation(t_list **a, t_list **b, char *op)
{
	if (starts_with(op, "p"))
	{
		if (!(ft_strlen(op) == 2 && ft_all_in(op + 1, "ab")))
			return (-1);
	}
	if (starts_with(op, "s"))
	{
		if (!(ft_strlen(op) == 2 && ft_all_in(op + 1, "abs")))
			return (-1);
	}
	if (starts_with(op, "rr"))
	{
		if (!(ft_strlen(op) == 3 && ft_all_in(op + 1, "abr")))
			return (-1);
	}
	if (starts_with(op, "r"))
	{
		if (!(ft_strlen(op) == 2 && ft_all_in(op + 1, "abr")))
			return (-1);
	}
	return (0);

}
