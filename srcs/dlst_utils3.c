/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 18:55:36 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/17 10:36:30 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	dlst_rev_rotate(t_dlst *head)
{
	t_dlst	*back;
	
	if (!head)
		return ;
	back = head->prev;
	dlst_swap(back, head);
}

void	dlst_push_top(t_dlst *from_head, t_dlst *to_head)
{
	t_dlst *elem;
	
	elem = from_head->next->next;
	dlst_add_front(to_head, from_head->next);
	elem->prev = from_head;
	from_head->next = elem;
}

t_dlst	*dlst_init(void)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if(!elem)
	{
		ft_putstr_fd("malloc error", 2);
		exit(1);
	}
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}