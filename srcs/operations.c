/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:11:49 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 00:44:59 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	dlst_add_back(stack->ans, dlst_new(SA));
	//ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack *stack)
{
	dlst_swap_front(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(SB));
	//ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack *stack)
{
	dlst_swap_front(stack->a_head);
	dlst_swap_front(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(SS));
	//ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack)
{
	dlst_push_top(stack->b_head, stack->a_head);
	dlst_add_back(stack->ans, dlst_new(PA));
	//ft_putstr_fd("pa\n", 1);
}

void	pb(t_stack *stack)
{
	dlst_push_top(stack->a_head, stack->b_head);
	dlst_add_back(stack->ans, dlst_new(PB));
	//ft_putstr_fd("pb\n", 1);
}
