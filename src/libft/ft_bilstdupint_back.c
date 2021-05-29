/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bilstdupint_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 10:18:25 by lzins             #+#    #+#             */
/*   Updated: 2021/05/29 10:20:23 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bilstdupint_back(t_bilist **alst, int k)
{
	int	*k_ptr;

	k_ptr = wrap_malloc(sizeof(int));
	*k_ptr = k;
	ft_bilstadd_back_content(alst, k);
}
