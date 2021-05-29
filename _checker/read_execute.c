/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_execute.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:03:02 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 11:18:19 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "get_next_line.h"

int	read_execute_cmds(t_stacks *stacks)
{
	char	*line;
	int		ret;

	ret = 1;
	while (ret == 1)
	{
		ret = get_next_line(STDIN_FILENO, &line);
		if (ret == 0 && ft_strlen(line) == 0)
		{
			free(line);
			break;
		}
		if (parse_operation(stacks, line) == -1)
			ret = -1;
		else if (stacks->verbose)
			print_stacks_side(stacks);
		free(line);
	}
	if (ret == -1)
		return (error_free(stacks));
	return (check_ok(stacks));
}
