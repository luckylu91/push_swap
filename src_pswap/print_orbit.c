/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_orbit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 09:01:02 by lzins             #+#    #+#             */
/*   Updated: 2021/03/31 09:12:42 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void print_orbit(t_list *orbit)
{
	char *str;

	str = orbit_str(orbit);
	ft_putstr_fd(str, STDOUT_FILENO);
	free(str);
}

static void	check_done(void *i, void *array)
{
	((int*)array)[*(int*)i] = 1;
}

int print_orbits(t_permut *permut)
{
	int		i;
	int		*array;
	t_list	*orbit;

	array = ft_calloc(permut->n, sizeof(int));
	if (!array)
		return (-1);
	i = 0;
	while (i < permut->n)
	{
		if (!array[i])
		{
			if (orbit_of(permut, i, &orbit) == -1)
			{
				free(array);
				return (-1);
			}
			print_orbit(orbit);
			ft_lstiter_arg(orbit, array, check_done);
			ft_lstclear(&orbit, free);
		}
		i++;
	}
	return (1);
}
