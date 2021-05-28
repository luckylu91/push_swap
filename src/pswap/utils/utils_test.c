/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_test.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 09:11:31 by lzins             #+#    #+#             */
/*   Updated: 2021/04/12 09:12:36 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void *char_from_int(void *i)
{
	return (ft_itoa(*(int*)i));
}

void print_int_list(t_list *lst, char *name)
{
	t_list *path_str = ft_lstmap(lst, char_from_int, free);
	char *str = ft_lststrjoin(path_str, ", ", "", "");
	ft_lstclear(&path_str, free);
	printf("%s\t: %s\n", name, str);
	free(str);
}

void print_pathinfo(t_pathinfo *pi)
{
	print_int_list(pi->path, "path");
	print_int_list(pi->dists, "dists");
	printf("len : %d\n", pi->len);
}

void	print_array(int *array, int n)
{
	int i;

	i = -1;
	while (++i < n)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
