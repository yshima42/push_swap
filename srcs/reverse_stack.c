/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:18:47 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/22 14:31:27 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rev_rrr(t_stack *stack, int32_t n_rrr)
{
	int32_t	i;

	i = 0;
	while (i < n_rrr)
	{
		rrr(stack);
		i++;
	}
}

static void	rev_rrb(t_stack *stack, int32_t n_rrb)
{
	int32_t	i;

	i = 0;
	while (i < n_rrb)
	{
		rrb(stack);
		i++;
	}
}

static void	rev_rra(t_stack *stack, int32_t n_rra)
{
	int32_t	i;

	i = 0;
	while (i < n_rra)
	{
		rra(stack);
		i++;
	}
}

void	reverse_stack(t_stack *stack, t_count *count)
{
	if (count->n_ra < count->n_rb)
	{
		rev_rrr(stack, count->n_ra);
		rev_rrb(stack, count->n_rb - count->n_ra);
	}
	else if (count->n_rb < count->n_ra)
	{
		rev_rrr(stack, count->n_rb);
		rev_rra(stack, count->n_ra - count->n_rb);
	}
	else
		rev_rrr(stack, count->n_ra);
}
