/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:55:36 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 12:40:27 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	dlst_rev_rotate(t_dlst *head)
{
	t_dlst	*back;

	if (!head || head->next == head || head->next->next == head)
		return (false);
	back = head->prev;
	dlst_swap(back, head);
	return (true);
}

bool	dlst_push_top(t_dlst *from_head, t_dlst *to_head)
{
	t_dlst	*elem;

	if (!from_head || !to_head || from_head->next == from_head)
		return (false);
	elem = from_head->next->next;
	dlst_add_front(to_head, from_head->next);
	elem->prev = from_head;
	from_head->next = elem;
	return (true);
}
