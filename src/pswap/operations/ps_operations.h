/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_operations.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/10 15:13:02 by lzins             #+#    #+#             */
/*   Updated: 2021/04/10 15:15:07 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_OPERATIONS_H
#define PS_OPERATIONS_H

#include "pswap.h"

int	ps_push_ab(t_pswap *ps, int op_code);
int	ps_swap_ab(t_pswap *ps, int op_code);
int	ps_rotate_ab(t_pswap *ps, int op_code);
int	ps_rotate_reverse_ab(t_pswap *ps, int op_code);

#endif
