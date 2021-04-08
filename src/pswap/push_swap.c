/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/08 14:50:54 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

int	*list_to_array(t_list *lst, int n)
{
	int *array;
	int i;

	array = ft_calloc(n, sizeof(int));
	if (!array)
		return (NULL);
	i = 0;
	while (i < n)
	{
		if (!lst)
		{
			free(array);
			return (NULL);
		}
		array[i] = int_at(lst);
		lst = lst->next;
		i++;
	}
	return (array);
}

int	main(int argc, char *argv)
{
	t_stacks	stacks;
	int			*array;
	t_permut	*permut;
	t_list		*path;
	t_list		*remaining;

	if (argc == 1)
		return (0);
	if (args_to_stacks(&stacks, argc, argv) == -1)
		return (-1);
	if (repeating_numbers(stacks.a))
		return (error_free(&stacks));
	array = list_to_array(stacks.a, stacks.n);
	if (!array)
		return (error_free(&stacks));
	permut = create_permut(array, stacks.n);
	path = chose_path(permut);
	if (!permut || update_all_paths(permut) == -1 || !path
		|| select_remaining(permut, path, &remaining) == -1)
	{
		destroy_permut(permut);
		free(path);
		return (error_free(&stacks));
	}
	
}
