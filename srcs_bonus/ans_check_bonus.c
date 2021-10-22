/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_check_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:33:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 14:37:47 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	operations_exec(t_stack *stack, int32_t ans)
{
	if (ans == PA)
		pa_exec(stack);
	else if (ans == PB)
		pb_exec(stack);
	else if (ans == SA)
		sa_exec(stack);
	else if (ans == SB)
		sb_exec(stack);
	else if (ans == SS)
		ss_exec(stack);
	else if (ans == RA)
		ra_exec(stack);
	else if (ans == RB)
		rb_exec(stack);
	else if (ans == RR)
		rr_exec(stack);
	else if (ans == RRA)
		rra_exec(stack);
	else if (ans == RRB)
		rrb_exec(stack);
	else if (ans == RRR)
		rrr_exec(stack);
}

static void	operations_exec_loop(t_stack *stack)
{
	t_dlst	*p;

	p = stack->ans->next;
	while (p != stack->ans)
	{
		operations_exec(stack, p->num);
		p = p->next;
	}
}

bool	ans_check(t_stack *stack, int32_t n_nums)
{
	int32_t	a_size;

	operations_exec_loop(stack);
	a_size = dlst_size(stack->a_head);
	if (is_sorted(stack->a_head, n_nums) && a_size == n_nums)
		return (true);
	else
		return (false);
}
