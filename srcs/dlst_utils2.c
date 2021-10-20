/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:53:29 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 20:44:50 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dlst_del_back(t_dlst *head)
{
	t_dlst	*elem;

	if (!head)
		return ;
	elem = head->prev;
	elem->prev->next = head;
	head->prev = elem->prev;
	free(elem);
}

void	dlst_add_front(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return ;
	new->prev = head;
	new->next = head->next;
	head->next->prev = new;
	head->next = new;
}

void	dlst_swap(t_dlst *a, t_dlst *b)
{
	t_dlst	*a_before;
	t_dlst	*b_after;

	if (!a || !b)
		return ;
	a_before = a->prev;
	b_after = b->next;
	if (a_before == b)
		return ;
	a_before->next = b;
	b->prev = a_before;
	b->next = a;
	a->prev = b;
	a->next = b_after;
	b_after->prev = a;
}

void	dlst_swap_front(t_dlst *head)
{
	if (!head)
		return ;
	dlst_swap(head->next, head->next->next);
}

void	dlst_rotate(t_dlst *head)
{
	t_dlst	*front;

	if (!head)
		return ;
	front = head->next;
	dlst_swap(head, front);
}
