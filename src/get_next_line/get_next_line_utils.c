/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 00:53:12 by lzins             #+#    #+#             */
/*   Updated: 2021/04/07 11:05:31 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	strccpy(char *dst, char *src, char c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n && src[i] && src[i] != c)
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

int		free_safe(char *line)
{
	if (line)
		free(line);
	return (-1);
}
