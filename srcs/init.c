/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:47:39 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 13:11:35 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dlst	*init_dlst(t_stack *stack)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if (!elem)
	{
		ft_putstr_fd("Error\n", 2);
		free(stack);
		exit(EXIT_FAILURE);
	}
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

t_stack	*init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	if (!stack)
	{
		ft_putstr_fd("Error\n", 2);
		exit(EXIT_FAILURE);
	}
	stack->a_head = init_dlst(stack);
	stack->b_head = init_dlst(stack);
	stack->ans = init_dlst(stack);
	return (stack);
}

void	init_count(t_count *count)
{
	count->n_pb = 0;
	count->n_ra = 0;
	count->n_rb = 0;
	count->n_pa = 0;
}
