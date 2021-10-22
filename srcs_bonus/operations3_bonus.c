/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:47:40 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 13:35:14 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	rra_exec(t_stack *stack)
{
	if (dlst_rev_rotate(stack->a_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	rrb_exec(t_stack *stack)
{
	if (dlst_rev_rotate(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	rrr_exec(t_stack *stack)
{
	if (dlst_rev_rotate(stack->a_head)
		&& dlst_rev_rotate(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}
