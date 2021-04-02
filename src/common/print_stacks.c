/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 15:06:52 by lzins             #+#    #+#             */
/*   Updated: 2021/04/02 12:01:54 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

static size_t compute_max_width(char **array, int n)
{
	size_t	size_i;
	size_t	max;
	int		i;

	max = 1;
	if (!array)
		return (max);
	i = 0;
	while (i < n)
	{
		size_i = ft_strlen(array[i]);
		if (size_i > max)
			max = size_i;
		i++;
	}
	return (max);
}

static void put_spaces(int n)
{
	int i;

	if (n <= 0)
		return;
	i = 0;
	while (i < n)
	{
		ft_putchar_fd(' ', STDOUT_FILENO);
		i++;
	}
}

static void print_arrays(char **array_a, char **array_b, t_stacks *stacks, size_t max_width[2])
{
	int		i;
	int		i_max;
	char	*s;

	if (stacks->a_size > stacks->b_size)
		i_max = stacks->a_size;
	else
		i_max = stacks->b_size;
	i = 0;
	while (i < i_max)
	{
		if (i >= i_max - stacks->a_size)
		{
			s = array_a[i - (i_max - stacks->a_size)];
			put_spaces(max_width[0] - ft_strlen(s));
			ft_putstr_fd(s, STDOUT_FILENO);
			ft_putchar_fd(' ', STDOUT_FILENO);
		}
		if (i >= i_max - stacks->b_size)
		{
			s = array_b[i - (i_max - stacks->b_size)];
			put_spaces(max_width[1] - ft_strlen(s));
			ft_putstr_fd(s, STDOUT_FILENO);
		}
			ft_putchar_fd('\n', STDOUT_FILENO);
		i++;
	}
}

#include <stdio.h>
void	print_stacks_side(t_stacks *stacks)
{
	char	**array_a;
	char	**array_b;
	size_t	max_width[2];

	array_a = NULL;
	array_b = NULL;
	printf("a_size = %d, b_size = %d / lstsizes : %d %d\n", stacks->a_size, stacks->b_size, ft_lstsize(stacks->a), ft_lstsize(stacks->b));
	ft_putendl_fd("- -", STDOUT_FILENO);
	if (lstrev_array(stacks->a, stacks->a_size, &array_a) == 1 &&
		lstrev_array(stacks->b, stacks->b_size, &array_b) == 1)
	{
		max_width[0] = compute_max_width(array_a, stacks->a_size);
		max_width[1] = compute_max_width(array_b, stacks->b_size);
		print_arrays(array_a, array_b, stacks, max_width);
		ft_arrayclear((void**)array_a, stacks->a_size);
		ft_arrayclear((void**)array_b, stacks->b_size);
	}
	ft_putendl_fd("- -", STDOUT_FILENO);
	ft_putendl_fd("a b\n", STDOUT_FILENO);
}
