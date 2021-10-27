/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:40:34 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/27 13:35:15 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	dlst_replace(t_dlst *ans, int32_t ope, int32_t *count)
{
	dlst_del_front(ans->next);
	ans->next->num = ope;
	(*count)++;
}

static void	dlst_cancel(t_dlst *p, int32_t *count)
{
	dlst_del_front(p);
	dlst_del_front(p);
	(*count)++;
}

static void	ans_replace(t_dlst *p, t_dlst *ans, int32_t *count)
{
	if (p->next != ans && p->next->next != ans)
	{
		if (p->next->num == SA && p->next->next->num == SB)
			dlst_replace(p, SS, count);
		else if (p->next->num == SB && p->next->next->num == SA)
			dlst_replace(p, SS, count);
		else if (p->next->num == RA && p->next->next->num == RB)
			dlst_replace(p, RR, count);
		else if (p->next->num == RB && p->next->next->num == RA)
			dlst_replace(p, RR, count);
		else if (p->next->num == RRA && p->next->next->num == RRB)
			dlst_replace(p, RR, count);
		else if (p->next->num == RRB && p->next->next->num == RRA)
			dlst_replace(p, RRR, count);
	}
}

static void	ans_cancel(t_dlst *p, t_dlst *ans, int32_t *count)
{
	if (p->next != ans && p->next->next != ans)
	{
		if (p->next->num == RA && p->next->next->num == RRA)
			dlst_cancel(p, count);
		else if (p->next->num == RRA && p->next->next->num == RA)
			dlst_cancel(p, count);
		else if (p->next->num == RB && p->next->next->num == RRB)
			dlst_cancel(p, count);
		else if (p->next->num == RRB && p->next->next->num == RB)
			dlst_cancel(p, count);
	}
}

bool	ans_cut(t_dlst *ans)
{
	t_dlst	*p;
	int32_t	count;

	count = 0;
	p = ans->next;
	while (p != ans)
	{
		ans_replace(p, ans, &count);
		ans_cancel(p, ans, &count);
		p = p->next;
	}
	return (count != 0);
}
