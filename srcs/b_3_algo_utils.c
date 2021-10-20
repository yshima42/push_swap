/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   B_3_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:43:02 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 20:43:04 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	b_3_bac(t_stack *stack)
{
	rb(stack);
	sb(stack);
	pa(stack);
	rrb(stack);
	pa(stack);
	pa(stack);
}

void	b_3_bca(t_stack *stack)
{
	pa(stack);
	sb(stack);
	pa(stack);
	pa(stack);
}

void	b_3_acb(t_stack *stack)
{
	sb(stack);
	pa(stack);
	sb(stack);
	pa(stack);
	pa(stack);
}

void	b_3_cab(t_stack *stack)
{
	sb(stack);
	pa(stack);
	pa(stack);
	pa(stack);
}

void	b_3_abc(t_stack *stack)
{
	rb(stack);
	sb(stack);
	pa(stack);
	pa(stack);
	rrb(stack);
	pa(stack);
}
