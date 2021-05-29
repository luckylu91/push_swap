/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_operation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 11:14:05 by lzins             #+#    #+#             */
/*   Updated: 2021/04/01 15:32:31 by lzins            ###   ########lyon.fr   */
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

static int op_code(char *op_name, char *prefix, char *suffixes)
{
	size_t	len_prefix;

	len_prefix = ft_strlen(prefix);
	if (starts_with(op_name, prefix))
	{
		if (ft_strlen(op_name) != len_prefix + 1)
			return (-1);
		return (ft_strindex(suffixes, op_name[len_prefix]));
	}
	return (-1);
}

int	parse_operation(t_stacks *stacks, char *op_name)
{
	int	ret;

	ret = op_code(op_name, "p", "ab");
	if (ret >= 0)
		return (push_ab(stacks, ret));
	ret = op_code(op_name, "s", "abs");
	if (ret >= 0)
		return (swap_ab(stacks, ret));
	ret = op_code(op_name, "r", "abr");
	if (ret >= 0)
		return (rotate_ab(stacks, ret));
	ret = op_code(op_name, "rr", "abr");
	if (ret >= 0)
		return (rotate_reverse_ab(stacks, ret));
	return (-1);
}
