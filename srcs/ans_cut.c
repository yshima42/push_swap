/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ans_cut.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yshimazu <yshimazu@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:40:34 by yshimazu          #+#    #+#             */
/*   Updated: 2021/10/19 20:40:35 by yshimazu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	dlst_replace(t_dlst *ans, int ope)
{
	dlst_del_front(ans->next);
	ans->next->num = ope;
}

static void	dlst_cancell(t_dlst *p)
{
	dlst_del_front(p);
	dlst_del_front(p);
}

static void	ans_replace(t_dlst *p)
{
	if (p->next->num == SA && p->next->next->num == SB)
		dlst_replace(p, SS);
	else if (p->next->num == SB && p->next->next->num == SA)
		dlst_replace(p, SS);
	else if (p->next->num == RA && p->next->next->num == RB)
		dlst_replace(p, RR);
	else if (p->next->num == RB && p->next->next->num == RA)
		dlst_replace(p, RR);
	else if (p->next->num == RRA && p->next->next->num == RRB)
		dlst_replace(p, RR);
	else if (p->next->num == RRB && p->next->next->num == RRA)
		dlst_replace(p, RRR);
}

static void	ans_cancell(t_dlst *p)
{
	if (p->next->num == RA && p->next->next->num == RRA)
		dlst_cancell(p);
	else if (p->next->num == RRA && p->next->next->num == RA)
		dlst_cancell(p);
	else if (p->next->num == RB && p->next->next->num == RRB)
		dlst_cancell(p);
	else if (p->next->num == RRB && p->next->next->num == RB)
		dlst_cancell(p);
}

void	ans_cut(t_dlst *ans)
{
	t_dlst	*p;

	p = ans->next;
	while (p != ans)
	{
		ans_replace(p);
		ans_cancell(p);
		p = p->next;
	}
}