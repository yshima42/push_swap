/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qsort_AtoB.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:16:20 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:39:43 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	a_3_algo(t_dlst *a_head, t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = a_head->next->num;
	b = a_head->next->next->num;
	c = a_head->next->next->next->num;
	if (b < a && a < c)
		a_3_bac(stack);
	else if (b < c && c < a)
		a_3_bca(stack);
	else if (c < b && b < a)
		a_3_cba(stack);
	else if (a < c && c < b)
		a_3_acb(stack);
	else if (c < a && a < b)
		a_3_cab(stack);
}

void	push_to_b(t_stack *stack, int size, t_pivots pivots, t_count *count)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (stack->a_head->next->num >= pivots.l_pivot)
		{
			ra(stack);
			(count->n_ra)++;
		}
		else
		{
			pb(stack);
			(count->n_pb)++;
			if (stack->b_head->next->num > pivots.s_pivot)
			{
				rb(stack);
				(count->n_rb)++;
			}
		}
		i++;
	}
}

bool	a_upto3(t_stack *stack, int size)
{
	if (size == 0)
		return (true);
	else if (size == 1)
		return (true);
	else if (size == 2)
	{
		algo_2(stack->a_head, stack);
		return (true);
	}
	else if (size == 3)
	{
		a_3_algo(stack->a_head, stack);
		return (true);
	}
	else
		return (false);
}

bool	a_is_sorted(t_dlst *head, int size)
{
	t_dlst	*p;
	int		i;

	p = head->next;
	i = 0;
	while (i < size)
	{
		if (p->num > p->next->num)
			return (false);
		p = p->next;
		i++;
	}
	return (true);
}

bool	atob_qsort(t_stack *stack, int size)
{
	t_pivots	pivots;
	t_count		count;

	init_count(&count);
	if (a_is_sorted(stack->a_head, size))
		return (true);
	if (a_upto3(stack, size))
		return (true);
	find_pivots(stack->a_head, size, &pivots);
	push_to_b(stack, size, pivots, &count);
	reverse_stack(stack, &count);
	atob_qsort(stack, count.n_ra);
	btoa_qsort(stack, count.n_rb);
	btoa_qsort(stack, count.n_pb - count.n_rb);
	return (true);
}
