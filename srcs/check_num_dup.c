/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_dup.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 00:18:18 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/21 00:18:18 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
				all_free_exit(stack, EXIT_FAILURE);
			}
			q = q->next;
		}
		p = p->next;
	}
}
