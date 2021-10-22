/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:38 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 12:26:49 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ra(t_stack *stack)
{
	if (dlst_rotate(stack->a_head))
		return (dlst_add_back(stack->ans, dlst_new(RA)));
	else
		return (false);
}

bool	rb(t_stack *stack)
{
	if (dlst_rotate(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(RB)));
	else
		return (false);
}

bool	rr(t_stack *stack)
{
	if (dlst_rotate(stack->a_head) && dlst_rotate(stack->b_head))
		return (dlst_add_back(stack->ans, dlst_new(RR)));
	else
		return (false);
}
