/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 13:45:25 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/23 10:48:13 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	dlst_free(t_dlst *head)
{
	t_dlst	*p;

	p = head->next;
	while (p != head)
	{
		p = p->next;
		free (p->prev);
	}
	free (head);
}

void	all_free_exit(t_stack *stack, int32_t exit_status)
{
	if (stack->a_head)
		dlst_free(stack->a_head);
	if (stack->b_head)
		dlst_free(stack->b_head);
	if (stack->ans)
		dlst_free(stack->ans);
	if (stack)
		free(stack);
	exit(exit_status);
}
