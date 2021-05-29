/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstrev_array.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 11:49:49 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:12:47 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static void	fill_array_fun(void *i, void *array_addr)
{
	**(char***)array_addr = ft_itoa(*(int*)i);
	(*(char***)array_addr)++;
}

static int is_null(void *s)
{
	return (!s);
}

int	lstrev_array(t_bilist *lst, int n, char ***array)
{
	char **array_mov;

	if (n == 0)
	{
		*array = NULL;
		return (1);
	}
	*array = malloc(n * sizeof(char*));
	if (!*array)
		return (-1);
	array_mov = *array;
	ft_lstiter(lst, &array_mov, fill_array_fun);
	if (ft_any((void*)*array, n, sizeof(char*), is_null))
	{
		ft_arrayclear((void**)*array, n);
		return (-1);
	}
	return (1);
}
