/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/30 16:10:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 20:28:30 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stacks(t_stack *stack)
{
	t_dlst *p;
	
	p = stack->a_head->next;
	while(p != stack->a_head)
	{
		printf("A: %d\n",p->num);
		p = p->next;
	}
	printf("\n");
	p = stack->b_head->next;
	while(p != stack->b_head)
	{
		printf("B: %d\n",p->num);
		p = p->next;
	}
}

static void	find_pivots_1st(t_dlst *dlst_head, int size, t_pivots *pivots)
{
	int	*array;

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
	push_to_b_1st(t_stack *stack, int size, t_pivots pivots, t_count *count)
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
			if (stack->b_head->next->num < pivots.s_pivot)
			{
				rb(stack);
				(count->n_rb)++;
			}
		}
		i++;
	}
}

bool	over_7(t_stack *stack, int size)
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

void	upto_6(t_stack *stack, int n_ags)
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

void	check_num_dup(t_dlst *head, t_stack *stack)
{
	t_dlst	*p;
	t_dlst	*q;

	p = head->next;
	while(p != head)
	{
		q = p->next;
		while (q != head)
		{
			if (p->num == q->num)
			{
				ft_putstr_fd("Error\n", 2);
				all_free(stack);
				exit(EXIT_FAILURE);
			}
			q = q->next;
		}
		p = p->next;
	}
}
//TO DO: all_free exitを作る
int	main(int ac, char **av)
{
	t_stack	*stack;
	int		n_nums;

	n_nums = ac - 1;
	args_check(n_nums, av);
	stack = init_stack();
	av_to_dlst(stack->a_head, n_nums, av, stack);
	check_num_dup(stack->a_head, stack);
	if (is_sorted(stack->a_head, n_nums))
	{
		all_free(stack);
		return (0);
	}
	if (n_nums <= 6)
		upto_6(stack, n_nums);
	else
		over_7(stack, dlst_size(stack->a_head));
	ans_cut(stack->ans);
	ans_cut(stack->ans);
	ans_output(stack->ans);
	all_free(stack);
	return (0);
}
