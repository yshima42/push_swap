/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_BtoA.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:18:02 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:40:11 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	b_3_algo(t_dlst *a_head, t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
	if (b < a && a < c)
		b_3_bac(stack);
	else if (b < c && c < a)
		b_3_bca(stack);
	else if (a < c && c < b)
		b_3_acb(stack);
	else if (c < a && a < b)
		b_3_cab(stack);
	else if (a < b && b < c)
		b_3_abc(stack);
	else
	{
		pa(stack);
		pa(stack);
		pa(stack);
	}
}

static void	push_to_a(t_stack *stack, int size, t_pivots pivots, t_count *count)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->b_head->next->num <= pivots.s_pivot)
		{
			rb(stack);
			(count->n_rb)++;
		}
		else
		{
			pa(stack);
			(count->n_pa)++;
			if (stack->a_head->next->num < pivots.l_pivot)
			{
				ra(stack);
				(count->n_ra)++;
			}
		}
		i++;
	}
}

static void	b_2_algo(t_dlst *head, t_stack *stack)
{
	if (head->next->num < head->next->next->num)
		sb(stack);
}

static bool	b_upto3(t_stack *stack, int b_size)
{
	if (b_size == 0)
		return (true);
	else if (b_size == 1)
	{
		pa(stack);
		return (true);
	}
	else if (b_size == 2)
	{
		b_2_algo(stack->b_head, stack);
		pa(stack);
		pa(stack);
		return (true);
	}
	else if (b_size == 3)
	{
		b_3_algo(stack->b_head, stack);
		return (true);
	}
	else
		return (false);
}

bool	btoa_qsort(t_stack *stack, int b_size)
{
	t_pivots	pivots;
	t_count		count;

	init_count(&count);
	if (b_upto3(stack, b_size))
		return (true);
	find_pivots(stack->b_head, b_size, &pivots);
	push_to_a(stack, b_size, pivots, &count);
	atob_qsort(stack, count.n_pa - count.n_ra);
	reverse_stack(stack, &count);
	atob_qsort(stack, count.n_ra);
	btoa_qsort(stack, count.n_rb);
	return (true);
}
