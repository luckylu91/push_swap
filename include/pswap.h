/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:33:21 by lzins             #+#    #+#             */
/*   Updated: 2021/04/24 10:51:18 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
#define PSWAP_H

#include "common.h"
#include "operations.h"

// utils
int	int_at(t_list *lst);
char	op_last_char(char op_char, int op_code);

t_stacks	*groupstacks(t_stacks *stacks);

int	merge_ab_headtail(t_stacks *gstacks);
int	merge_ab_tailhead(t_stacks *gstacks);

#endif
