/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:15:22 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/15 19:19:07 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack *stack)
{
	dlst_rev_rotate(stack->a_head);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack *stack)
{
	dlst_rev_rotate(stack->b_head);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack *stack)
{
	dlst_rev_rotate(stack->a_head);
	dlst_rev_rotate(stack->b_head);
	ft_putstr_fd("rrr\n", 1);
}