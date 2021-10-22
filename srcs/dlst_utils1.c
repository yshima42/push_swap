/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:49:21 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 14:36:32 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_dlst	*dlst_new(int32_t num)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if (!elem)
		return (NULL);
	elem->prev = elem;
	elem->next = elem;
	elem->num = num;
	return (elem);
}

int32_t	dlst_size(t_dlst *head)
{
	size_t	size;
	t_dlst	*p;

	if (!head)
		return (0);
	size = 0;
	p = head->next;
	while (p != head)
	{
		p = p->next;
		size++;
	}
	return (size);
}

bool	dlst_add_back(t_dlst *head, t_dlst *new)
{
	if (!head || !new)
		return (false);
	new->next = head;
	new->prev = head->prev;
	head->prev->next = new;
	head->prev = new;
	return (true);
}

bool	dlst_del_front(t_dlst *head)
{
	t_dlst	*elem;

	if (!head)
		return (false);
	elem = head->next;
	elem->next->prev = head;
	head->next = elem->next;
	free(elem);
	return (true);
}

bool	dlst_del(t_dlst *elem)
{
	t_dlst	*front;
	t_dlst	*back;

	if (!elem || elem->next == elem)
		return (false);
	front = elem->next;
	back = elem->prev;
	back->next = front;
	front->prev = back;
	free(elem);
	return (true);
}
