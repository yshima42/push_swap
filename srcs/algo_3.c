/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 11:11:27 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:43:04 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo_3(t_dlst *a_head, t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
	if (b < a && a < c)
		sa(stack);
	else if (b < c && c < a)
		ra(stack);
	else if (c < b && b < a)
	{
		sa(stack);
		rra(stack);
	}
	else if (a < c && c < b)
	{
		sa(stack);
		ra(stack);
	}
	else if (c < a && a < b)
		rra(stack);
}
