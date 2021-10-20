/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_3_algo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:30:52 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 20:30:57 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_3_bac(t_stack *stack)
{
	sa(stack);
}

void	a_3_bca(t_stack *stack)
{
	sa(stack);
	ra(stack);
	sa(stack);
	rra(stack);
}

void	a_3_cba(t_stack *stack)
{
	sa(stack);
	ra(stack);
	sa(stack);
	rra(stack);
	sa(stack);
}

void	a_3_acb(t_stack *stack)
{
	ra(stack);
	sa(stack);
	rra(stack);
}

void	a_3_cab(t_stack *stack)
{
	ra(stack);
	sa(stack);
	rra(stack);
	sa(stack);
}
