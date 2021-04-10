/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 13:50:02 by lzins            ###   ########lyon.fr   */
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

static int	array_to_stacks(t_stacks *stacks, int n, int *array)
{
	int i;

	stacks->n = n;
	stacks->a_size = n;
	stacks->b_size = 0;
	i = 0;
	while (i < n)
	{
		if (ft_lstdupint_back(&stacks->a, array[i]) == -1)
			return (error_free(stacks));
		i++;
	}
	stacks->a_size = n;
	return (1);
}

int	main(int argc, char **argv)
{
	t_stacks	stacks;
	int			ret_args;
	t_stacks	stacks_bij;
	int			*array;
	t_permut	*permut;
	t_list		*path;
	t_list		*remaining;

	ret_args = handle_args(&stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	array = list_to_array(stacks.a, stacks.n);
	if (!array)
		return (error_free(&stacks));
	permut = create_permut(array, stacks.n);
	if (array_to_stacks(&stacks_bij, permut->n, permut->array_trans) == -1)
		return (error_free_all(...));
	path = chose_path(permut);
	if (!permut || update_all_paths(permut) == -1 || !path
		|| select_remaining(permut, path, &remaining) == -1)
	{
		destroy_permut(permut);
		free(path);
		return (error_free(&stacks));
	}

}
