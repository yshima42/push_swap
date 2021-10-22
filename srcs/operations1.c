/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:11:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 12:36:33 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	sa(t_stack *stack)
{
	if (dlst_swap_front(stack->a_head))
		return (dlst_add_back(stack->ans, dlst_new(SA)));
	else
		return (false);
}

bool	sb(t_stack *stack)
{
	if (dlst_swap_front(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(SB)));
	else
		return (false);
}

bool	ss(t_stack *stack)
{
	if (dlst_swap_front(stack->a_head) && dlst_swap_front(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(SS)));
	else
		return (false);
}

bool	pa(t_stack *stack)
{
	if (dlst_push_top(stack->b_head, stack->a_head))
		return (dlst_add_back(stack->ans, dlst_new(PA)));
	else
		return (false);
}

bool	pb(t_stack *stack)
{
	if (dlst_push_top(stack->a_head, stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(PB)));
	else
		return (false);
}
