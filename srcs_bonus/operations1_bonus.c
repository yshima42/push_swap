/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:45:45 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 22:13:38 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	sa_exec(t_stack *stack)
{
	if (dlst_swap_front(stack->a_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	sb_exec(t_stack *stack)
{
	if (dlst_swap_front(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	ss_exec(t_stack *stack)
{
	if (dlst_swap_front(stack->a_head) 
		|| dlst_swap_front(stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	pa_exec(t_stack *stack)
{
	if (dlst_push_top(stack->b_head, stack->a_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}

bool	pb_exec(t_stack *stack)
{
	if (dlst_push_top(stack->a_head, stack->b_head))
		return (true);
	else
	{
		ko_output_exit(stack);
		return (false);
	}
}
