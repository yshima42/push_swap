/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:46:46 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 13:34:56 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	ra_exec(t_stack *stack)
{
	if (dlst_rotate(stack->a_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}	

bool	rb_exec(t_stack *stack)
{
	if (dlst_rotate(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	rr_exec(t_stack *stack)
{
	if (dlst_rotate(stack->a_head)
		&& dlst_rotate(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}
