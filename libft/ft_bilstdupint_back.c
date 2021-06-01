/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstdupint_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:18:25 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 22:38:20 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bilstdupint_back(t_bilist **alst, int k)
{
	int	*k_ptr;

	k_ptr = wrap_malloc(sizeof(int));
	*k_ptr = k;
	ft_bilstadd_back_content(alst, k_ptr);
}
