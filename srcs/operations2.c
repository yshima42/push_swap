/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:14:38 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 00:45:10 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack *stack)
{
	dlst_rotate(stack->a_head);
	dlst_add_back(stack->ans, dlst_new(RA));
	//ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack *stack)
{
	dlst_rotate(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(RB));
	//ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack *stack)
{
	dlst_rotate(stack->a_head);
	dlst_rotate(stack->b_head);
	dlst_add_back(stack->ans, dlst_new(RR));
	//ft_putstr_fd("rr\n", 1);	
}