/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:11:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:22:56 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	dlst_add_back(stack->ans, dlst_new(SA));
}

void	sb(t_stack *stack)
{
	dlst_swap_front(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(SB));
}

void	ss(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	dlst_swap_front(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(SS));
}

void	pa(t_stack *stack)
{
	dlst_push_top(stack->b_head, stack->a_head);
	dlst_add_back(stack->ans, dlst_new(PA));
}

void	pb(t_stack *stack)
{
	dlst_push_top(stack->a_head, stack->b_head);
	dlst_add_back(stack->ans, dlst_new(PB));
}
