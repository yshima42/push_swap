/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_456.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:08:53 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:29:19 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static bool	is_closer_front(t_dlst *a_head, t_dlst *p_s)
{
	int		dis_front;
	int		dis_back;
	t_dlst	*p;

	dis_front = 0;
	dis_back = 0;
	p = a_head;
	while (p != p_s)
	{
		p = p->next;
		dis_front++;
	}
	p = a_head;
	while (p != p_s)
	{
		p = p->prev;
		dis_back++;
	}
	if (dis_front <= dis_back)
		return (true);
	else
		return (false);
}

static void	push_to_b_456(t_stack *stack)
{
	t_dlst	*p;
	t_dlst	*p_s;
	int		size;

	size = dlst_size(stack->a_head);
	while (size > 3)
	{
		p = stack->a_head->next;
		p_s = stack->a_head->next;
		while (p != stack->a_head)
		{
			if (p->num < p_s->num)
				p_s = p;
			p = p->next;
		}
		if (is_closer_front(stack->a_head, p_s))
			while (stack->a_head->next != p_s)
				ra(stack);
		else
			while (stack->a_head->next != p_s)
				rra(stack);
		pb(stack);
		size = dlst_size(stack->a_head);
	}
}

static void	push_to_a_456(t_stack *stack)
{
	t_dlst	*p;

	p = stack->b_head->next;
	while (p != stack->b_head)
	{
		p = p->next;
		pa(stack);
	}
}

void	algo_456(t_stack *stack)
{
	push_to_b_456(stack);
	algo_3(stack->a_head, stack);
	push_to_a_456(stack);
}
