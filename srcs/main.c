/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/25 14:06:43 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	find_pivots_1st(t_dlst *dlst_head, int32_t size, t_pivots *pivots)
{
	int32_t	*array;

	array = dlst_to_array(dlst_head, size);
	array_qsort(array, 0, size - 1);
	pivots->s_pivot = array[size / 3];
	if (size % 3 == 2)
		pivots->l_pivot = array[size * 2 / 3 - 1];
	else
		pivots->l_pivot = array[size * 2 / 3];
	free(array);
}

static void	
	push_to_b_1st(t_stack *stack, int32_t size, t_pivots pivots, t_count *count)
{
	int32_t	i;

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
			if (stack->b_head->next->num < pivots.s_pivot)
			{
				rb(stack);
				(count->n_rb)++;
			}
		}
		i++;
	}
}

static bool	over_7(t_stack *stack, int32_t size)
{
	t_pivots	pivots;
	t_count		count;

	init_count(&count);
	if (a_upto3(stack, size))
		return (true);
	find_pivots_1st(stack->a_head, size, &pivots);
	push_to_b_1st(stack, size, pivots, &count);
	atob_qsort(stack, count.n_ra);
	btoa_qsort(stack, count.n_rb);
	btoa_qsort(stack, count.n_pb - count.n_rb);
	return (true);
}

static void	upto_6(t_stack *stack, int32_t n_ags)
{
	if (n_ags == 1)
		;
	else if (n_ags == 2)
		algo_2(stack->a_head, stack);
	else if (n_ags == 3)
		algo_3(stack->a_head, stack);
	else if (n_ags <= 6)
		algo_456(stack);
}

int	main(int32_t ac, char **av)
{
	t_stack	*stack;
	int32_t	n_nums;

	n_nums = ac - 1;
	args_check(n_nums);
	stack = init_stack();
	av_to_dlst(stack->a_head, n_nums, av, stack);
	check_num_dup(stack->a_head, stack);
	if (is_sorted(stack->a_head, n_nums))
		all_free_exit(stack, EXIT_SUCCESS);
	if (n_nums <= 6)
		upto_6(stack, n_nums);
	else
		over_7(stack, n_nums);
	ans_cut(stack->ans);
	ans_cut(stack->ans);
	ans_output(stack->ans);
	all_free_exit(stack, EXIT_SUCCESS);
	return (0);
}
