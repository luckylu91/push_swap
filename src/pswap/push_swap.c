/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 14:23:23 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 14:04:37 by lzins            ###   ########lyon.fr   */
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
	t_pswap		ps;
	int			ret_args;
	int			*array;

	ft_bzero(&ps, sizeof(t_pswap));
	ret_args = handle_args(&ps.stacks, argc, argv);
	if (ret_args != 1)
		return (ret_args);
	array = list_to_array(ps.stacks.a, ps.stacks.n);
	if (!array)
		return (error_free(&ps.stacks));
	ps.permut = create_permut(array, ps.stacks.n);
	// need ? print -> use stacks et bij array
	if (array_to_stacks(&ps.stacks_bij, ps.permut->n, ps.permut->array_trans) == -1)
		return (error_free_all(...));
	ps.path = chose_path(ps.permut);
	if (!ps.permut || update_all_paths(ps.permut) == -1 || !ps.path
		|| select_remaining(ps.permut, ps.path, &ps.remaining) == -1)
	{
		destroy_permut(ps.permut);
		free(ps.path);
		return (error_free(&ps.stacks));
	}

}
