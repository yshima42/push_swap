/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:53:29 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 21:52:52 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	dlst_del_back(t_dlst *head)
{
	t_dlst	*elem;

	if (!head)
		return (false);
	elem = head->prev;
	elem->prev->next = head;
	head->prev = elem->prev;
	free(elem);
	return (true);
}

bool	dlst_add_front(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return (false);
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
	return (true);
}

bool	dlst_swap(t_dlst *a, t_dlst *b)
{
	t_dlst	*a_before;
	t_dlst	*b_after;

	if (!a || !b)
		return (false);
	a_before = a->prev;
	b_after = b->next;
	if (a_before == b)
		return (false);
	a_before->next = b;
	b->prev = a_before;
	b->next = a;
	a->prev = b;
	a->next = b_after;
	b_after->prev = a;
	return (true);
}

bool	dlst_swap_front(t_dlst *head)
{
	if (!head || head->next == head)
		return (false);
	dlst_swap(head->next, head->next->next);
	return (true);
}

bool	dlst_rotate(t_dlst *head)
{
	t_dlst	*front;

	if (!head || head->next == head)
		return (false);
	front = head->next;
	dlst_swap(head, front);
	return (true);
}
