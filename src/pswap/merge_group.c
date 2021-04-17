/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_group.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lzins <lzins@student.42lyon.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/17 13:23:40 by lzins             #+#    #+#             */
/*   Updated: 2021/04/17 13:56:56 by lzins            ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

static	t_list *remove_tail(t_list **lst)
{
	t_list *last;
	t_list *last_prev;

	if (!*lst)
		return (NULL);
	last = *lst;
	last_prev = NULL;
	while(last->next)
	{
		last_prev = last;
		last = last->next;
	}
	if (last_prev)
		last_prev->next = NULL;
	else
		*lst = NULL;
	return (last);
}

static	t_list *remove_head(t_list **lst)
{
	t_list *first;
	t_list *second;

	if (!*lst)
		return (NULL);
	second = (*lst)->next;
	first = *lst;
	first->next = NULL;
	*lst = second;
	return (first);
}

/* Modify the groups, merging a's head and b's tail into b's head
*  Return : number of operations (sum of the two groups' sizes)
*/
int	merge_ab_headtail(t_stacks *gstacks)
{
	t_list	*a_head;
	t_list	*b_tail;
	int		n;

	a_head = remove_head(gstacks->a);
	b_tail = remove_tail(gstacks->b);
	n = int_at(a_head) + int_at(b_tail);
	*(int *)a_head = n;
	ft_lstdelone(b_tail, free);
	push(&a_head, gstacks->b);
	gstacks->a_size--;
	return (n);
}

/* Modify the groups, merging b's head and a's tail into a's head
*  Return : number of operations (sum of the two groups' sizes)
*/
int	merge_ab_tailhead(t_stacks *gstacks)
{
	t_list	*a_tail;
	t_list	*b_head;
	int		n;

	a_tail = remove_tail(gstacks->a);
	b_head = remove_head(gstacks->b);
	n = int_at(a_tail) + int_at(b_head);
	*(int *)a_tail = n;
	ft_lstdelone(b_head, free);
	push(&a_tail, gstacks->a);
	gstacks->b_size--;
	return (n);
}
