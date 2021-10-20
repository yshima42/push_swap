/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:47:39 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/20 11:22:26 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_dlst	*init_dlst(void)
{
	t_dlst	*elem;

	elem = (t_dlst *)malloc(sizeof(t_dlst));
	if (!elem)
	{
		ft_putstr_fd("malloc error", 2);
		exit(1);
	}
	elem->prev = elem;
	elem->next = elem;
	return (elem);
}

t_stack	*init_stack(void)
{
	t_stack	*elem;

	elem = (t_stack *)malloc(sizeof(t_stack));
	if (!elem)
	{
		perror("Error\nmalloc");
		exit(EXIT_FAILURE);
	}
	elem->a_head = init_dlst();
	elem->b_head = init_dlst();
	elem->ans = init_dlst();
	return (elem);
}

void	init_count(t_count *count)
{
	count->n_pb = 0;
	count->n_ra = 0;
	count->n_rb = 0;
	count->n_pa = 0;
}
