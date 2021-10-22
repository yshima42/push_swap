/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:22 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 12:35:09 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rra(t_stack *stack)
{
	if (dlst_rev_rotate(stack->a_head))
		return (dlst_add_back(stack->ans, dlst_new(RRA)));
	else
		return (false);
}

bool	rrb(t_stack *stack)
{
	if (dlst_rev_rotate(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(RRB)));
	else
		return (false);
}

bool	rrr(t_stack *stack)
{
	if (dlst_rev_rotate(stack->a_head) && dlst_rev_rotate(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(RRR)));
	else
		return (false);
}
