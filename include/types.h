/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:54:43 by lzins             #+#    #+#             */
/*   Updated: 2021/06/02 02:40:04 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H
# define TYPES_H

# include "libft.h"

typedef struct	s_dequeue
{
	t_bilist	*first;
	t_bilist	*last;
	int			size;
}	t_dequeue;

typedef struct	s_stacks
{
	t_dequeue	*a;
	t_dequeue	*b;
	t_dequeue	*a_sorted;
	int			n;
	int			verbose;
}				t_stacks;

typedef struct	s_push_movement
{
	int	direction;
	int	size;
}	t_push_movement;

typedef	struct s_push_strat
{
	int	n;
	int	n_push;
	int	k;
	int	first_dir;
	int	*indices;
}	t_push_strat;

typedef struct s_bool_fun_arg
{
	t_bool_fun	f;
	int			arg2;
}	t_bool_fun_arg;

#endif
